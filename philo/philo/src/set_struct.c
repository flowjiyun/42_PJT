/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:30:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 20:42:02 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	set_input(t_input *input, int argc, char **argv)
{
	input->num_of_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->num_must_eat = ft_atoi(argv[5]);
	else
		input->num_must_eat = -1;
	return (true);
}

bool	set_fork(t_fork *fork, t_input *input)
{
	fork->is_occupied = malloc(sizeof(bool) * input->num_of_philo);
	if (!fork->is_occupied)
		return (false);
	memset(fork->is_occupied, 0, sizeof(bool) * input->num_of_philo);
	if (pthread_mutex_init(&(fork->usaged_lock), NULL) != 0)
		return (false);
	return (true);
}

bool	set_philo(t_philo *philo, t_fork *fork, t_input *input)
{
	philo->philosophers = malloc(sizeof(pthread_t) * input->num_of_philo);
	if (!(philo->philosophers))
		return (false);
	philo->state = malloc(sizeof(int) * input->num_of_philo);
	if (!(philo->state))
		return (false);
	memset(philo->state, 0, sizeof(int) * input->num_of_philo);
	if (pthread_mutex_init(&(philo->state_lock), NULL) != 0)
		return (false);
	philo->fork = fork;
	philo->input = input;
	return (true);
}
