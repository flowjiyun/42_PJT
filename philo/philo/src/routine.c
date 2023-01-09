/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:33:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/09 16:01:38 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	// 쓰레드 생성 표시 남기기
	pthread_mutex_lock(&philo->shared_data->created_flag_lock);
	philo->shared_data->is_philo_created[philo->thread_id] = true;
	pthread_mutex_unlock(&philo->shared_data->created_flag_lock);
	// 다른쓰레드 모두 생성될 때 까지 대기
	while (true)
	{
		if (philo->shared_data->start_flag == true)
			break ;
	}
	printf("thread_id : %d, sec : %ld, microsec : %d\n", philo->thread_id, philo->shared_data->simulation_start_time.tv_sec, philo->shared_data->simulation_start_time.tv_usec);
	// eating();
	// putdown_fork();
	// sleeping();
	// thinking();
	return (NULL);
}
