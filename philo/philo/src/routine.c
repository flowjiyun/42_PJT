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

int	putdown_fork(t_philo *philo)
{
	pthread_mutex_t	*fork_flag_lock;
	const int		philo_num = philo->input->num_of_philo;
	const int		left = philo->thread_id;
	const int		right = (left + (philo_num - 1)) % philo_num;

	fork_flag_lock = philo->shared_data->fork_flag_lock;
	if (pthread_mutex_unlock(&fork_flag_lock[right]) != 0)
		return (-1);
	if (pthread_mutex_unlock(&fork_flag_lock[left]) != 0)
		return (-1);
	return (0);
}

int	pickup_fork(t_philo *philo)
{
	pthread_mutex_t	*fork_flag_lock;
	const int		philo_num = philo->input->num_of_philo;
	const int		left = philo->thread_id;
	const int		right = (left + (philo_num - 1)) % philo_num;

	fork_flag_lock = philo->shared_data->fork_flag_lock;
	if (pthread_mutex_lock(&fork_flag_lock[left]) != 0)
		return (-1);
	if (pthread_mutex_lock(&fork_flag_lock[right]) != 0)
		return (-1);
	print_status(philo, HAS_FORK);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_status(philo, THINKING);
	return (0);
}

int	eating(t_philo *philo)
{
	struct timeval	cur_timeval;
	const int		id = philo->thread_id;

	gettimeofday(&cur_timeval, NULL);
	if (pthread_mutex_lock(&philo->shared_data->time_lock) != 0)
		return (-1);
	philo->time->prev_eat_timeval = cur_timeval;
	if (pthread_mutex_unlock(&philo->shared_data->time_lock) != 0)
		return (-1);
	if (pthread_mutex_lock(&philo->shared_data->meal_count_lock) != 0)
		return (-1);
	++philo->shared_data->num_of_meal[id];
	if (pthread_mutex_unlock(&philo->shared_data->meal_count_lock) != 0)
		return (-1);
	print_status(philo, EATING);
	ft_usleep(philo->input->time_to_eat * 1000);
	return (0);
}

int	sleeping(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ft_usleep(philo->input->time_to_sleep * 1000);
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->shared_data->start_flag_lock);
	pthread_mutex_unlock(&philo->shared_data->start_flag_lock);
	if (!(philo->thread_id & 1))
		ft_usleep(philo->input->time_to_eat);
	while (true)
	{
		if (thinking(philo) != 0)
			break ;
		if (pickup_fork(philo) != 0)
			break ;
		if (eating(philo) != 0)
			break ;
		if (putdown_fork(philo) != 0)
			break ;
		if (sleeping(philo) != 0)
			break ;
	}
	return (NULL);
}
