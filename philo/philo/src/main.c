/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:36 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 17:09:16 jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_start_timeval(t_philo **philo_arr, int num_of_philo)
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

int	main(int argc, char **argv)
{
	t_philo			**philo_arr;
	t_input			*input;
	t_shared_data	*shared_data;
	int				monitoring_signal;

	if ((argc != 5 && argc != 6) || is_valid_input(argv) == false)
	{
		ft_putendl_fd("Error : argument error", 2);
		return (1);
	}
	input = set_input(argc, argv);
	if (!input)
	{
		ft_putendl_fd("Error : set_input error", 2);
		return (1);
	}
	shared_data = set_shared_data(input);
	if (!shared_data)
	{
		ft_putendl_fd("Error : set_fork error", 2);
		return (1);
	}
	philo_arr = set_philo(shared_data, input);
	if (!philo_arr)
	{
		ft_putendl_fd("Error : set_philo error", 2);
		return (1);
	}
	pthread_mutex_lock(&shared_data->start_flag_lock);
	if (create_philo(philo_arr, input->num_of_philo) == false)
	{
		ft_putendl_fd("Error : create_philo error", 2);
		return (1);
	}
	if (set_start_timeval(philo_arr, input->num_of_philo) != 0)
		return (1);
	pthread_mutex_unlock(&shared_data->start_flag_lock);
	monitoring_signal = monitoring(philo_arr, shared_data,
			input->num_of_philo, argc);
	if (monitoring_signal == -1)
		return (1);
	else
		destroy_mutex(shared_data, input->num_of_philo);
	return (0);
}
