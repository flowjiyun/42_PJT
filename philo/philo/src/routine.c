/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:33:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/10 12:57:56by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	deadlock 방지
  1. 짝수번째 철학자는 왼쪽 포크를 먼저 들려고 계속 시도한다.
		// 락 걸기
		a. 왼쪽에 포크가 있는지 확인
		b. 있으면 들기
			//락해제
			break ;
		// 락 해제
  2. 홀수번째 철학자는 오른쪽 포크를 먼저 든다
*/

void	pick_left_fork(int id, int philo_num, bool *fork_arr,
	pthread_mutex_t fork_flag_lock)
{
	while (true)
	{
		pthread_mutex_lock(&fork_flag_lock);
		if (fork_arr[id] == false)
		{
			fork_arr[id] = true;
			pthread_mutex_unlock(&fork_flag_lock);
			break ;
		}
		pthread_mutex_unlock(&fork_flag_lock);
	}
}

void	pick_right_fork(int id, int philo_num, bool *fork_arr,
	pthread_mutex_t fork_flag_lock)
{
	while (true)
	{
		pthread_mutex_lock(&fork_flag_lock);
		if (fork_arr[(id + (philo_num - 1)) % philo_num] == false)
		{
			fork_arr[(id + (philo_num - 1)) % philo_num] = true;
			pthread_mutex_unlock(&fork_flag_lock);
			break ;
		}
		pthread_mutex_unlock(&fork_flag_lock);
	}
}

long	get_cur_time(struct timeval base_timeval)
{
	struct timeval	cur_timeval;
	long			cur_time;
	long			base_time;

	gettimeofday(&cur_timeval, NULL);
	cur_time = cur_timeval.tv_sec * 1000 + cur_timeval.tv_usec / 1000;
	base_time = base_timeval.tv_sec * 1000 + base_timeval.tv_usec / 1000;
	return (cur_time - base_time);
}

void	print_status(t_philo *philo, int status)
{
	long	cur_time;

	cur_time = get_cur_time(philo->simulation_start_time);
	if (status == HAS_FORK)
		printf(HAS_FORK_MESSAGE, cur_time, philo->thread_id);
	else if (status == EATING)
		printf(EATING_MESSAGE, cur_time, philo->thread_id);
	else if (status == SLEEPING)
		printf(SLEEPING_MESSAGE, cur_time, philo->thread_id);
	else if (status == THINKING)
		printf(THINKING_MESSAGE, cur_time, philo->thread_id);
	else
		printf(DIED_MESSAGE, cur_time, philo->thread_id);
}

void	putdown_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*fork_arr;
	pthread_mutex_t	fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	fork_arr = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	pthread_mutex_lock(&fork_flag_lock);
	fork_arr[id] = false;
	fork_arr[(id + (philo_num - 1)) % philo_num] = false;
	pthread_mutex_unlock(&fork_flag_lock);
}

void	pickup_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*fork_arr;
	pthread_mutex_t	fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	fork_arr = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	if (philo->thread_id % 2 == 0)
	{
		pick_left_fork(id, philo_num, fork_arr, fork_flag_lock);
		pick_right_fork(id, philo_num, fork_arr, fork_flag_lock);
		print_status(philo, HAS_FORK);
	}
	else
	{
		pick_right_fork(id, philo_num, fork_arr, fork_flag_lock);
		pick_left_fork(id, philo_num, fork_arr, fork_flag_lock);
		print_status(philo, HAS_FORK);
	}
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINKING);
}

void	eating(t_philo *philo)
{
	struct timeval	cur_time;

	print_status(philo, EATING);
	usleep(philo->input->time_to_eat);
	gettimeofday(&cur_time, NULL);
	philo->prev_eat_time = cur_time;
}

void	sleeping(t_philo *philo)
{	
	struct timeval	cur_timeval;

	print_status(philo, SLEEPING);
	usleep(philo->input->time_to_sleep);
	gettimeofday(&cur_timeval, NULL);

}

void	ready_simulation(t_philo *philo)
{
	// 쓰레드 생성 표시 남기기
	pthread_mutex_lock(&philo->shared_data->created_flag_lock);
	philo->shared_data->is_philo_created[philo->thread_id] = true;
	pthread_mutex_unlock(&philo->shared_data->created_flag_lock);
	// 다른쓰레드 모두 생성될 때 까지 대기
	while (true)
	{
		pthread_mutex_lock(&philo->shared_data->start_flag_lock);
		if (philo->shared_data->start_flag == true)
		{
			pthread_mutex_unlock(&philo->shared_data->start_flag_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->shared_data->start_flag_lock);
	}
}

// 철학자 죽음 감지 로직 추가 필요
// is_philo_dead
// 1. 처음 시뮬레이션 시작해서 밥을 특정 시간동안 못먹으면 죽음
// 2. 밥을 먹고 나서 부터 다음 밥을 먹는 시간까지 특정 시간을 넘어가면 죽음
// 3. 사망하면 사망 플래그 세움
// 철학자 생각하는 중
void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	ready_simulation(philo);
	while (true)
	{
		thinking(philo);
		// pickup_fork(philo);
		// eating(philo);
		// putdown_fork(philo);
		// sleeping(philo);
	}
	return (NULL);
}
