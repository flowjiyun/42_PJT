/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:19:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/16 16:24:52 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_status_first(unsigned long cur_time, int thread_id, int status)
{
	if (status == HAS_FORK)
	{
		if (printf(HAS_FORK_MESSAGE, cur_time, thread_id + 1) < 0)
			return (-1);
	}
	else if (status == EATING)
	{
		if (printf(EATING_MESSAGE, cur_time, thread_id + 1) < 0)
			return (-1);
	}
	else if (status == SLEEPING)
	{
		if (printf(SLEEPING_MESSAGE, cur_time, thread_id + 1) < 0)
			return (-1);
	}
	return (0);
}

static int	print_status_second(unsigned long cur_time, int thread_id, int status)
{
	if (status == THINKING)
	{
		if (printf(THINKING_MESSAGE, cur_time, thread_id + 1) < 0)
			return (-1);
	}
	else if (status == DIED)
	{
		if (printf(DIED_MESSAGE, cur_time, thread_id + 1) < 0)
			return (-1);
	}
	return (0);
}

int	print_status(t_philo *philo, int status)
{
	unsigned long	cur_time;

	cur_time = get_time_from_base(philo->time->simulation_start_timeval);
	// if (pthread_mutex_lock(&philo->shared_data->dead_flag_lock) != 0)
	// 	return (-1);
	// if (philo->shared_data->is_philo_dead == false)
	// {
		if (print_status_first(cur_time, philo->thread_id, status) != 0)
			return (-1);
		if (print_status_second(cur_time, philo->thread_id, status) != 0)
			return (-1);
	// }
	// if (pthread_mutex_unlock(&philo->shared_data->dead_flag_lock) != 0)
	// 	return (-1);
	return (0);
}
