/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:33:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/16 16:13:14 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_died(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->shared_data->dead_flag_lock) != 0)
		return (-1);
	if (philo->shared_data->is_philo_dead == true)
	{
		if (pthread_mutex_unlock(&philo->shared_data->dead_flag_lock) != 0)
			return (-1);
		if (putdown_fork(philo) != 0)
			return (-1);
		return (0);
	}
	if (pthread_mutex_unlock(&philo->shared_data->dead_flag_lock) != 0)
		return (-1);
	return (1);
}

static int	dining(t_philo *philo)
{
	while (true)
	{
		if (is_died(philo) != 1)
			break ;
		if (thinking(philo) != 0)
			break ;
		if (is_died(philo) != 1)
			break ;
		if (pickup_fork(philo) != 0)
			break ;
		if (is_died(philo) != 1)
			break ;
		if (eating(philo) != 0)
			break ;
		if (putdown_fork(philo) != 0)
			break ;
		if (is_died(philo) != 1)
			break ;
		if (sleeping(philo) != 0)
			break ;
	}	
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (pthread_mutex_lock(&philo->shared_data->start_flag_lock) != 0)
		return (NULL);
	if (pthread_mutex_unlock(&philo->shared_data->start_flag_lock) != 0)
		return (NULL);
	if (!(philo->thread_id & 1))
	{
		if (ft_usleep(philo->input->time_to_eat) != 0)
			return (NULL);
	}
	if (dining(philo) == 0)
		return (NULL);
	return (NULL);
}
