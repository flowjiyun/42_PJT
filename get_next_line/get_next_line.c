/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/13 19:39:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char **backup, char *buf)
{
	ssize_t	byte;

	while (is_newline(*backup) == -1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{	
			if (*backup)
				free(*backup);
			free(buf);
			return (NULL);
		}
		if (byte == 0)
			break ;
		buf[byte] = '\0';
		if (!(*backup))
			*backup = ft_strdup(buf);
		else
			*backup = ft_strjoin(*backup, buf);
		if (!(*backup))
			return (NULL);
	}
	free(buf);
	return (*backup);
}

char	*get_line(char **backup)
{
	char			*temp;
	unsigned int	len;

	if ((*backup)[0] == '\0')
		return (NULL);
	len = 0;
	while ((*backup)[len] && (*backup)[len] != '\n')
		len++;
	if ((*backup)[len] == '\n')
	{
		temp = (char *)malloc(sizeof(char) * (len + 2));
		if (!temp)
			return (NULL);
		ft_memcopy(temp, *backup, len + 1);
		++len;
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (len + 1));
		if (!temp)
			return (NULL);
		ft_memcopy(temp, *backup, len);
	}
	temp[len] = '\0';
	return (temp);
}

static char	*ft_substr(char *str, int start, unsigned int size)
{
	unsigned int	i;
	char			*ret;

	if (!size)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[start++];
	ret[i] = '\0';
	return (ret);
}

static char	*update_backup(char **backup)
{
	char			*temp;
	unsigned int	index_s;

	if (is_newline(*backup) == -1)
	{
		free(*backup);
		return (NULL);
	}
	else
	{
		index_s = is_newline(*backup) + 1;
		temp = ft_substr(*backup, index_s, (ft_strlen(*backup) - index_s));
		free(*backup);
		return (temp);
	}
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	backup = read_file(fd, &backup, buf);
	if (!backup)
		return (NULL);
	line = get_line(&backup);
	if (!line)
	{
		free(backup);
		return (NULL);
	}
	backup = update_backup(&backup);
	return (line);
}
