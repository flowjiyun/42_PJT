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

int	main(int argc, char **argv)
{
	t_philo		**philo_arr;
	t_input		*input;
	t_fork		*fork;

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
	fork = set_fork(input);
	if (!fork)
	{
		ft_putendl_fd("Error : set_fork error", 2);
		return (1);
	}
	philo_arr = set_philo(fork, input);
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
	if (wait_philo(philo_arr, input->num_of_philo) == false)
	{
		ft_putendl_fd("Error : wait_philo error", 2);
		return (1);
	}
	printf("hello");
	return (0);
}
