/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:50:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/12 13:44:50 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

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
	}
}

int	main(void)
{
	struct timeval	start;
	struct timeval	end;
	gettimeofday(&start, NULL);
	printf("%ld\n", start.tv_sec * 1000 + start.tv_usec / 1000);
	ft_usleep(200 * 1000);
	// usleep(200 * 1000);
	gettimeofday(&end, NULL);
	printf("%ld\n", end.tv_sec * 1000 + end.tv_usec / 1000);
	return (0);
}
