/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:34:54 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 21:07:08 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->num_of_philo)
	{
		if (pthread_create(&(philo->philosophers[i]), NULL,
				routine, philo) != 0)
			return (false);
		++i;
	}
	return (true);
}
