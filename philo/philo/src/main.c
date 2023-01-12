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

bool	is_any_philo_dead(t_shared_data *shared_data, int num_of_philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&shared_data->dead_flag_lock);
	while (i < num_of_philo)
	{
		if (shared_data->is_philo_dead[i] == true)
		{
			pthread_mutex_unlock(&shared_data->dead_flag_lock);
			return (true);
		}
		++i;
	}
	pthread_mutex_unlock(&shared_data->dead_flag_lock);
	return (false);
}

bool	is_all_philo_created(t_shared_data *shared_data, int num_of_philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&shared_data->created_flag_lock);
	while (i < num_of_philo)
	{
		if (shared_data->is_philo_created[i] == false)
		{
			pthread_mutex_unlock(&shared_data->created_flag_lock);
			return (false);
		}
		++i;
	}
	pthread_mutex_unlock(&shared_data->created_flag_lock);
	return (true);
}

void	set_start_timeval(t_philo **philo_arr, int num_of_philo)
{
	int				i;
	struct timeval	start_timeval;

	i = 0;
	gettimeofday(&start_timeval, NULL);
	while (i < num_of_philo)
	{
		philo_arr[i]->simulation_start_timeval = start_timeval;
		philo_arr[i]->prev_eat_timeval = start_timeval;
		++i;
	}
}

void	monitor_philo_created(t_input *input, t_shared_data *shared_data, t_philo **philo_arr)
{
	while (true)
	{
		if (is_all_philo_created(shared_data, input->num_of_philo) == true)
		{
			set_start_timeval(philo_arr, input->num_of_philo);
			pthread_mutex_lock(&shared_data->start_flag_lock);
			shared_data->start_flag = true;
			pthread_mutex_unlock(&shared_data->start_flag_lock);
			break ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo			**philo_arr;
	t_input			*input;
	t_shared_data	*shared_data;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("Error : argument number error", 2);
		return (1);
	}
	if (is_valid_input(argv) == false)
	{
		ft_putendl_fd("Error : argument format error", 2);
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
	if (create_philo(philo_arr, input->num_of_philo) == false)
	{
		ft_putendl_fd("Error : create_philo error", 2);
		return (1);
	}
	monitor_philo_created(input, shared_data, philo_arr);
	while (true)
	{
		// if (argc == 6
		// 	&& has_enough_meal(shared_data, input->num_of_philo) == true)
		// {
		// 	terminate_philo(philo_arr, input->num_of_philo);
		// 	return (0);
		// }
		if (is_any_philo_dead(shared_data, input->num_of_philo) == true)
		{
			terminate_philo(philo_arr, input->num_of_philo);
			destroy_mutex(shared_data, input->num_of_philo);
			return (1);
		}
	}
	// if (wait_philo(philo_arr, input->num_of_philo) == false)
	// {
	// 	ft_putendl_fd("Error : wait_philo error", 2);
	// 	return (1);
	// }
	// terminate_philo(philo_arr, input->num_of_philo);
	// destroy_mutex(shared_data);
	// printf("hello");
	return (0);
}
