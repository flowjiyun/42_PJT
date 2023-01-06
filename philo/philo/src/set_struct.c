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

t_fork	*set_fork(t_input *input)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->is_occupied = malloc(sizeof(bool) * input->num_of_philo);
	if (!fork->is_occupied)
		return (NULL);
	memset(fork->is_occupied, 0, sizeof(bool) * input->num_of_philo);
	if (pthread_mutex_init(&(fork->usaged_lock), NULL) != 0)
		return (NULL);
	return (fork);
}

t_philo	**set_philo(t_fork *fork, t_input *input)
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
		philo_arr[i]->fork = fork;
		philo_arr[i]->input = input;
		++i;
	}
	return (philo_arr);
}
