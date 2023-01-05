/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:34:49 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 21:07:01 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wait_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->num_of_philo)
	{
		if (pthread_join(philo->philosophers[i], NULL) != 0)
			return (false);
		++i;
	}
	return (true);
}
