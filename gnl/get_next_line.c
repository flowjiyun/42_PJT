/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/21 20:37:29 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *buff, int fd)
{
	char		*temp;
	ssize_t		size;

	size = read(fd, buff, BUFFER_SIZE);
	if (size < 0)
		return (0);
	while (size >= 0)
	{
		buff[size] = 0;
		if (ft_strchr(buff, '\n'))
			return (ft_strjoin(temp, buff));
		size = read(fd, buff, )
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup_ptr;
	char		*buff;
	char		*line;


	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	backup_ptr = read_file(buff, fd);
	if (!backup_ptr)
		return (0);
	free(buff);
	line = get_line(backup_ptr);
}
