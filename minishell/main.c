/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:04 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/11 09:23:14 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define ITER 2

int	main(void)
{
	int	fd_now[2];
	int	fd_prev[2];
	int	fd_in;
	int	fd_out;
	int	i;
	int	ret;

	i = -1;
	while (++i < ITER)
	{
		pipe(fd_now);
		ret = fork();
		if (ret == 0)
		{
			if (i == 0)
				fd_in = open("infile", O_RDONLY);
			dup2(fd)
				
		}
		
	}
	

	return (0);
}