/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/18 11:37:47 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data_type(void *shared_data_type, int num_of_philo, int byte)
{
	bool	**bool_type;
	int		**int_type;

	if (byte == 1)
	{
		bool_type = (bool **)shared_data_type;
		*bool_type = malloc(byte * num_of_philo);
		if (!(*bool_type))
			return (-1);
		memset(*bool_type, 0, byte * num_of_philo);
	}
	else
	{
		int_type = (int **)shared_data_type;
		*int_type = malloc(byte * num_of_philo);
		if (!(*int_type))
			return (-1);
		memset(*int_type, 0, byte * num_of_philo);
	}
	return (0);
}

static int	init_mutex_lock(t_shared_data **shared_data, int philo_num)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&((*shared_data)->start_flag_lock), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&((*shared_data)->time_lock), NULL) != 0)
		return (-1);
	(*shared_data)->fork_flag_lock = malloc(sizeof(pthread_mutex_t)
			* philo_num);
	while (i < philo_num)
	{
		if (pthread_mutex_init(&((*shared_data)->fork_flag_lock[i]), NULL) != 0)
			return (-1);
		++i;
	}
	if (pthread_mutex_init(&((*shared_data)->dead_flag_lock), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&((*shared_data)->meal_count_lock), NULL) != 0)
		return (-1);
	return (0);
}

t_shared_data	*set_shared_data(t_input *input)
{
	t_shared_data	*shared_data;
	int				philo_num;

	shared_data = malloc(sizeof(t_shared_data));
	if (!shared_data)
		return (NULL);
	philo_num = input->num_of_philo;
	shared_data->is_philo_dead = false;
	if (init_data_type(&(shared_data->num_of_meal), philo_num,
			sizeof(int)) != 0)
		return (NULL);
	if (init_mutex_lock(&shared_data, philo_num) != 0)
		return (NULL);
	return (shared_data);
}

t_philo	**set_philo(t_shared_data *shared_data, t_input *input)
{
	t_philo	**philo_arr;
	int		i;

	philo_arr = malloc(sizeof(t_philo *) * input->num_of_philo);
	if (!philo_arr)
		return (NULL);
	i = 0;
	while (i < input->num_of_philo)
	{
		philo_arr[i] = malloc(sizeof(t_philo));
		if (!philo_arr[i])
			return (NULL);
		philo_arr[i]->thread_id = i;
		philo_arr[i]->thread = malloc(sizeof(pthread_t));
		if (!philo_arr[i]->thread)
			return (NULL);
		philo_arr[i]->shared_data = shared_data;
		philo_arr[i]->input = input;
		philo_arr[i]->time = malloc(sizeof(t_time));
		if (!philo_arr[i]->time)
			return (NULL);
		++i;
	}
	return (philo_arr);
}

t_input	*set_input(int argc, char **argv)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (NULL);
	input->num_of_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->num_must_eat = ft_atoi(argv[5]);
	else
		input->num_must_eat = 0;
	return (input);
}
