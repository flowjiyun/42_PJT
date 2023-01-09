/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:34:49 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/09 14:36:31 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	terminate_philo(t_philo **philo_arr, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_detach(*(philo_arr[i]->thread)) != 0)
			return (false);
		++i;
	}
	return (true);
}

bool	wait_philo(t_philo **philo_arr, int num_of_philo)
{
	int	i;

	i = 0;
	while (i < num_of_philo)
	{
		if (pthread_join(*(philo_arr[i]->thread), NULL) != 0)
			return (false);
		++i;
	}
	return (true);
}
