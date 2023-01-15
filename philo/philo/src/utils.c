/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:46:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/15 20:49:34 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_shared_data *shared_data, int philo_num)
{
	int	i;

	if (pthread_mutex_destroy(&shared_data->start_flag_lock) != 0)
		return (-1);
	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_destroy(&shared_data->fork_flag_lock[i]) != 0)
			return (-1);
		++i;
	}
	if (pthread_mutex_destroy(&shared_data->dead_flag_lock) != 0)
		return (-1);
	if (pthread_mutex_destroy(&shared_data->meal_count_lock) != 0)
		return (-1);
	return (0);
}

long	get_time_from_base(struct timeval base_timeval)
{
	struct timeval	cur_timeval;
	long			cur_time;
	long			base_time;

	if (gettimeofday(&cur_timeval, NULL) != 0)
		return (-1);
	cur_time = cur_timeval.tv_sec * 1000 + cur_timeval.tv_usec / 1000;
	base_time = base_timeval.tv_sec * 1000 + base_timeval.tv_usec / 1000;
	return (cur_time - base_time);
}

int	ft_usleep(useconds_t sleep_time)
{
	struct timeval	timeval_after_usleep;
	struct timeval	cur_time;
	long			expected_time;
	long			time_after_usleep;

	if (gettimeofday(&cur_time, NULL) != 0)
		return (-1);
	expected_time = (cur_time.tv_sec * 1000000 + cur_time.tv_usec)
		+ sleep_time;
	if (usleep(sleep_time * 0.8) != 0)
		return (-1);
	while (true)
	{
		if (gettimeofday(&timeval_after_usleep, NULL) != 0)
			return (-1);
		time_after_usleep = timeval_after_usleep.tv_sec * 1000000
			+ timeval_after_usleep.tv_usec;
		if (expected_time <= time_after_usleep)
			break ;
		// usleep(100);
	}
	return (0);
}

void	free_all(t_philo **philo_arr, t_shared_data *shared_data,
	t_input *input)
{
	const int	num_of_philo = input->num_of_philo;
	int			i;

	i = 0;
	free(input);
	free(shared_data->fork_flag_lock);
	free(shared_data->is_philo_dead);
	free(shared_data->num_of_meal);
	free(shared_data);
	while (i < num_of_philo)
	{
		free(philo_arr[i]->thread);
		free(philo_arr[i]->time);
		free(philo_arr[i]);
		++i;
	}
	free(philo_arr);
}
