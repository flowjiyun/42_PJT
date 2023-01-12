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

long	get_time_from_base(struct timeval base_timeval)
{
	struct timeval	cur_timeval;
	long			cur_time;
	long			base_time;

	gettimeofday(&cur_timeval, NULL);
	cur_time = cur_timeval.tv_sec * 1000 + cur_timeval.tv_usec / 1000;
	base_time = base_timeval.tv_sec * 1000 + base_timeval.tv_usec / 1000;
	return (cur_time - base_time);
}

void	ft_usleep(useconds_t sleep_time)
{
	struct timeval	timeval_after_usleep;
	struct timeval	cur_time;
	long			expected_time;
	long			time_after_usleep;

	gettimeofday(&cur_time, NULL);
	expected_time = (cur_time.tv_sec * 1000000 + cur_time.tv_usec)
		+ sleep_time;
	usleep(sleep_time * 0.8);
	while (true)
	{
		gettimeofday(&timeval_after_usleep, NULL);
		time_after_usleep = timeval_after_usleep.tv_sec * 1000000
			+ timeval_after_usleep.tv_usec;
		if (expected_time <= time_after_usleep)
			break ;
	}
}

void	print_status(t_philo *philo, int status)
{
	long	cur_time;

	cur_time = get_time_from_base(philo->simulation_start_timeval);
	if (status == HAS_FORK)
		printf(HAS_FORK_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == EATING)
		printf(EATING_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == SLEEPING)
		printf(SLEEPING_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == THINKING)
		printf(THINKING_MESSAGE, cur_time, philo->thread_id + 1);
	else
		printf(DIED_MESSAGE, cur_time, philo->thread_id + 1);
}

bool	check_philo_dead(t_philo *philo)
{
	long	time;

	time = get_time_from_base(philo->prev_eat_timeval);
	// printf("check %i dead time : %ld\n", philo->thread_id + 1, time);
	if (time >= philo->input->time_to_die)
	{
		pthread_mutex_lock(&philo->shared_data->dead_flag_lock);
		// printf("dead time : %ld\n", time);
		philo->shared_data->is_philo_dead[philo->thread_id] = true;
		pthread_mutex_unlock(&philo->shared_data->dead_flag_lock);
		return (true);
	}
	return (false);
}

int	pick_left_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*is_fork_occupied;
	pthread_mutex_t	*fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	is_fork_occupied = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	while (true)
	{
		if (check_philo_dead(philo) == true)
		{
			print_status(philo, DIED);
			return (-1);
		}
		pthread_mutex_lock(&fork_flag_lock[id]);
		if (is_fork_occupied[id] == false)
		{
			is_fork_occupied[id] = true;
			pthread_mutex_unlock(&fork_flag_lock[id]);
			break ;
		}
		pthread_mutex_unlock(&fork_flag_lock[id]);
	}
	return (0);
}

int	pick_right_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*is_fork_occupied;
	pthread_mutex_t	*fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	is_fork_occupied = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	while (true)
	{
		if (check_philo_dead(philo) == true)
		{
			print_status(philo, DIED);
			return (-1);
		}
		pthread_mutex_lock(&fork_flag_lock[(id + (philo_num - 1)) % philo_num]);
		if (is_fork_occupied[(id + (philo_num - 1)) % philo_num] == false)
		{
			is_fork_occupied[(id + (philo_num - 1)) % philo_num] = true;
			pthread_mutex_unlock(&fork_flag_lock[(id + (philo_num - 1)) % philo_num]);
			break ;
		}
		pthread_mutex_unlock(&fork_flag_lock[(id + (philo_num - 1)) % philo_num]);
	}
	return (0);
}

void	put_left_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*is_fork_occupied;
	pthread_mutex_t	*fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	is_fork_occupied = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	pthread_mutex_lock(&fork_flag_lock[id]);
	is_fork_occupied[id] = false;
	pthread_mutex_unlock(&fork_flag_lock[id]);
}

void	put_right_fork(t_philo *philo)
{
	int				id;
	int				philo_num;
	bool			*is_fork_occupied;
	pthread_mutex_t	*fork_flag_lock;

	id = philo->thread_id;
	philo_num = philo->input->num_of_philo;
	is_fork_occupied = philo->shared_data->is_fork_occupied;
	fork_flag_lock = philo->shared_data->fork_flag_lock;
	pthread_mutex_lock(&fork_flag_lock[(id + (philo_num - 1)) % philo_num]);
	is_fork_occupied[(id + (philo_num - 1)) % philo_num] = false;
	pthread_mutex_unlock(&fork_flag_lock[(id + (philo_num - 1)) % philo_num]);
}

void	putdown_fork(t_philo *philo)
{
	if (philo->thread_id % 2 == 0)
	{
		put_left_fork(philo);
		put_right_fork(philo);
	}
	else
	{
		put_right_fork(philo);
		put_left_fork(philo);
	}
}

int	pickup_fork(t_philo *philo)
{
	if (philo->thread_id % 2 == 0)
	{
		if (pick_left_fork(philo) == -1)
			return (-1);
		if (pick_right_fork(philo) == -1)
			return (-1);
		print_status(philo, HAS_FORK);
	}
	else
	{
		if (pick_right_fork(philo) == -1)
			return (-1);
		if (pick_left_fork(philo) == -1)
			return (-1);
		print_status(philo, HAS_FORK);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINKING);
}

void	eating(t_philo *philo)
{
	struct timeval	cur_timeval;

	print_status(philo, EATING);
	gettimeofday(&cur_timeval, NULL);
	philo->prev_eat_timeval = cur_timeval;
	ft_usleep(philo->input->time_to_eat * 1000);
}

int	sleeping(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ft_usleep(philo->input->time_to_sleep * 1000);
	if (check_philo_dead(philo) == true)
	{
		print_status(philo, DIED);
		return (-1);
	}
	return (0);
}

void	ready_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->created_flag_lock);
	philo->shared_data->is_philo_created[philo->thread_id] = true;
	pthread_mutex_unlock(&philo->shared_data->created_flag_lock);
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

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	ready_simulation(philo);
	if (philo->input->num_of_philo % 2 != 0)
	{
		if (philo->thread_id % 2 == 0)
			ft_usleep(philo->input->time_to_eat);
	}
	else
	{
		if (philo->thread_id % 2 != 0)
			ft_usleep(philo->input->time_to_eat);
	}
	while (true)
	{
		if (pickup_fork(philo) == -1)
			break ;
		eating(philo);
		putdown_fork(philo);
		if (sleeping(philo) == -1)
			break ;
		thinking(philo);
	}
	return (NULL);
}
