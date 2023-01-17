/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:16:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/17 14:12:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	clean_all(t_philo **philo_arr, t_shared_data *t_shared_data,
	t_input *input)
{
	if (wait_philo(philo_arr, input->num_of_philo) != 0)
		return (-1);
	destroy_mutex(t_shared_data, input->num_of_philo);
	free_all(philo_arr, t_shared_data, input);
	return (0);
}

static int	set_start_timeval(t_philo **philo_arr, int num_of_philo)
{
	int				i;
	struct timeval	start_timeval;

	i = 0;
	if (gettimeofday(&start_timeval, NULL) != 0)
		return (-1);
	while (i < num_of_philo)
	{
		philo_arr[i]->time->simulation_start_timeval = start_timeval;
		philo_arr[i]->time->prev_eat_timeval = start_timeval;
		++i;
	}
	return (0);
}

static int	init_struct(t_input **input, t_shared_data **shared_data,
	t_philo ***philo_arr)
{
	*shared_data = set_shared_data(*input);
	if (!*shared_data)
		return (-1);
	*philo_arr = set_philo(*shared_data, *input);
	if (!*philo_arr)
		return (-1);
	return (0);
}

static int	do_monitor(t_philo **philo_arr, t_shared_data *shared_data,
	t_input *input, int argc)
{
	const int	num_of_philo = input->num_of_philo;
	int			monitoring_signal;

	monitoring_signal = monitoring(philo_arr, shared_data, num_of_philo, argc);
	if (monitoring_signal == -1)
		return (-1);
	else
	{
		if (pthread_mutex_lock(&shared_data->dead_flag_lock) != 0)
			return (-1);
		shared_data->is_philo_dead = true;
		if (pthread_mutex_unlock(&shared_data->dead_flag_lock) != 0)
			return (-1);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_philo			**philo_arr;
	t_input			*input;
	t_shared_data	*shared_data;

	if ((argc != 5 && argc != 6) || is_valid_input(argv) == false)
		return (1);
	input = set_input(argc, argv);
	if (!input)
		return (1);
	if (init_struct(&input, &shared_data, &philo_arr) != 0)
		return (1);
	if (pthread_mutex_lock(&shared_data->start_flag_lock) != 0)
		return (1);
	if (create_philo(philo_arr, input->num_of_philo) != 0)
		return (1);
	if (set_start_timeval(philo_arr, input->num_of_philo) != 0)
		return (1);
	if (pthread_mutex_unlock(&shared_data->start_flag_lock) != 0)
		return (1);
	if (do_monitor(philo_arr, shared_data, input, argc) != 0)
		return (1);
	if (clean_all(philo_arr, shared_data, input) != 0)
		return (1);
	return (0);
}
