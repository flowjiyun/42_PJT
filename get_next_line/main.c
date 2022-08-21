/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:56:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/21 17:08:55 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("./test.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			break ;
		i++;
	}
	return (0);
}
