/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:22:59 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/21 20:37:31 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	buff[];
	int	fd = open("./text.txt", O_RDONLY);
	ssize_t size = read(fd, buff, 6);
	printf("%zu\n", size);
	for (int i = 0; i < 7; i++)
		printf("%d", buff[i]);
	printf("%s", buff);
	return (0);
}