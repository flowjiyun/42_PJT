/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:56:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/18 19:15:58 by jiyunpar         ###   ########.fr       */
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
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	return (0);
}
