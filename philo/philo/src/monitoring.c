/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:53:00 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/16 14:15:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	any_philo_dead(t_philo **philo_arr, t_shared_data *shared_data,
	int num_of_philo)
{
	int		i;
	unsigned long	time;

	i = 0;
	if (pthread_mutex_lock(&shared_data->time_lock) != 0)
		return (-1);
	while (i < num_of_philo)
	{
		time = get_time_from_base(philo_arr[i]->time->prev_eat_timeval);
		if (time < 0)
			return (-1);
		if (time >= philo_arr[i]->input->time_to_die)
		{
			if (print_status(philo_arr[i], DIED) != 0)
				return (-1);
			if (pthread_mutex_unlock(&shared_data->time_lock) != 0)
				return (-1);
			return (0);
		}
		++i;
	}
	if (pthread_mutex_unlock(&shared_data->time_lock) != 0)
		return (-1);
	return (1);
}

static int	all_philo_eat_enough(t_philo **philo_arr,
	t_shared_data *shared_data, int num_of_philo)
{
	int			i;
	const int	max_eat = philo_arr[0]->input->num_must_eat;

	i = 0;
	if (pthread_mutex_lock(&shared_data->meal_count_lock) != 0)
		return (-1);
	while (i < num_of_philo)
	{
		if (shared_data->num_of_meal[i] < max_eat)
		{
			if (pthread_mutex_unlock(&shared_data->meal_count_lock) != 0)
				return (-1);
			return (1);
		}
		++i;
	}
	if (pthread_mutex_unlock(&shared_data->meal_count_lock) != 0)
		return (-1);
	return (0);
}

int	monitoring(t_philo	**philo_arr, t_shared_data *shared_data,
	int num_of_philo, int argc)
{
	int	dead_signal;
	int	eat_signal;

	while (true)
	{
		if (argc == 6)
		{
			eat_signal = all_philo_eat_enough(philo_arr, shared_data,
					num_of_philo);
			if (eat_signal == 0)
				return (0);
			else if (eat_signal == -1)
				return (-1);
		}
		dead_signal = any_philo_dead(philo_arr, shared_data, num_of_philo);
		if (dead_signal == 0)
			return (0);
		else if (dead_signal == -1)
			return (-1);
	}
}
