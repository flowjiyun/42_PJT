/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:46:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/13 16:07:51 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_from_base(struct timeval base_timeval)
{
	struct timeval	cur_timeval;
	long			cur_time;
	long			base_time;

	gettimeofday(&cur_timeval, NULL);
	cur_time = cur_timeval.tv_sec * 1000 + cur_timeval.tv_usec / 1000;
	base_time = base_timeval.tv_sec * 1000 + base_timeval.tv_usec / 1000;
	return (cur_time - base_time);
}

void	ft_usleep(useconds_t sleep_time)
{
	struct timeval	timeval_after_usleep;
	struct timeval	cur_time;
	long			expected_time;
	long			time_after_usleep;

	gettimeofday(&cur_time, NULL);
	expected_time = (cur_time.tv_sec * 1000000 + cur_time.tv_usec)
		+ sleep_time;
	usleep(sleep_time * 0.8);
	while (true)
	{
		gettimeofday(&timeval_after_usleep, NULL);
		time_after_usleep = timeval_after_usleep.tv_sec * 1000000
			+ timeval_after_usleep.tv_usec;
		if (expected_time <= time_after_usleep)
			break ;
	//	usleep(150);
	}
}

void	print_status(t_philo *philo, int status)
{
	long	cur_time;

	cur_time = get_time_from_base(philo->time->simulation_start_timeval);
	if (status == HAS_FORK)
		printf(HAS_FORK_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == EATING)
		printf(EATING_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == SLEEPING)
		printf(SLEEPING_MESSAGE, cur_time, philo->thread_id + 1);
	else if (status == THINKING)
		printf(THINKING_MESSAGE, cur_time, philo->thread_id + 1);
	else
		printf(DIED_MESSAGE, cur_time, philo->thread_id + 1);
}