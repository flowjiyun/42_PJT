/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:56:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/22 16:16:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
		{
			printf("%s", str);
			break ;
		}
		write(1, str, strlen(str));
		free(str);
	}
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm -rf leaks_result_temp");
	return (0);
}
