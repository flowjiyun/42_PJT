/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/06 15:56:40y jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		input->num_must_eat = -1;
	return (input);
}

static bool	init_data_type(void *shared_data_type, int num_of_philo, int byte)
{
	bool	**bool_type;
	int		**int_type;

	if (byte == 1)
	{
		bool_type = (bool **)shared_data_type;
		*bool_type = malloc(byte * num_of_philo);
		if (!(*bool_type))
			return (false);
		memset(*bool_type, 0, byte * num_of_philo);
	}
	else
	{
		int_type = (int **)shared_data_type;
		*int_type = malloc(byte * num_of_philo);
		if (!(*int_type))
			return (false);
		memset(*int_type, 0, byte * num_of_philo);
	}
	return (true);
}

static bool	init_mutex_lock(t_shared_data **shared_data, int philo_num)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&((*shared_data)->start_flag_lock), NULL) != 0)
		return (false);
	if (pthread_mutex_init(&((*shared_data)->time_lock), NULL) != 0)
		return (false);
	(*shared_data)->fork_flag_lock = malloc(sizeof(pthread_mutex_t)
			* philo_num);
	while (i < philo_num)
	{
		if (pthread_mutex_init(&((*shared_data)->fork_flag_lock[i]), NULL) != 0)
			return (false);
		++i;
	}
	if (pthread_mutex_init(&((*shared_data)->dead_flag_lock), NULL) != 0)
		return (false);
	if (pthread_mutex_init(&((*shared_data)->meal_count_lock), NULL) != 0)
		return (false);
	return (true);
}

bool	destroy_mutex(t_shared_data *shared_data, int philo_num)
{
	int	i;

	if (pthread_mutex_destroy(&shared_data->start_flag_lock) == false)
		return (false);
	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_destroy(&shared_data->fork_flag_lock[i]) == false)
			return (false);
		++i;
	}
	if (pthread_mutex_destroy(&shared_data->dead_flag_lock) == false)
		return (false);
	if (pthread_mutex_destroy(&shared_data->meal_count_lock) == false)
		return (false);
	return (true);
}

t_shared_data	*set_shared_data(t_input *input)
{
	t_shared_data	*shared_data;
	int				philo_num;

	shared_data = malloc(sizeof(t_shared_data));
	if (!shared_data)
		return (NULL);
	philo_num = input->num_of_philo;
	if (init_data_type(&(shared_data->is_philo_dead), philo_num,
			sizeof(bool)) == false)
		return (NULL);
	if (init_data_type(&(shared_data->num_of_meal), philo_num,
			sizeof(int)) == false)
		return (NULL);
	if (init_mutex_lock(&shared_data, philo_num) == false)
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
