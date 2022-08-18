/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/18 19:46:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*check_list(t_list *list, int fd)
{
	t_file	*cur_file;
	t_file	*last_file;

	cur_file = list->head;
	while (cur_file)
	{
		if (cur_file->fd == fd)
			return (cur_file);
		last_file = cur_file;
		cur_file = cur_file->next;
	}
	cur_file = (t_file *)malloc(sizeof(t_file));
	if (cur_file)
	{
		cur_file->backup = NULL;
		cur_file->fd = fd;
		cur_file->next = NULL;
		(list->len)++;
	}
	if (list->len <= 1)
		list->head = cur_file;
	else
		last_file->next = cur_file;
	return (cur_file);
}

void	delete_list(t_list *list, t_file *cur_file)
{
	int		i;
	t_file	*temp;

	if (!cur_file->backup)
	{
		i = 0;
		temp = list->head;
		while (temp)
		{
			if (temp->fd == cur_file->fd)
				break ;
			i++;
			temp = temp->next;
		}
		if (i == 0)
			list->head = cur_file->next;
		else if (i < list->len)
			(cur_file - 1)->next = cur_file->next;
		else
			(cur_file - 1)->next = NULL;
		(list->len)--;
		free(cur_file->backup);
		free(cur_file);
	}
}

char	*read_file(t_file *cur_file, int fd)
{
	char	*buf;
	ssize_t	byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf[0] = '\0';
	while (!is_nl(buf))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == EOF_FLAG)
			break ;
		if (byte == ERROR)
		{
			if (cur_file->backup)
				free(cur_file->backup);
			return (0);
		}
		buf[byte] = 0;
		cur_file->backup = ft_strjoin(cur_file->backup, buf);
		if (!cur_file->backup)
			return (0);
	}
	free(buf);
	return (cur_file->backup);
}

char	*make_line(t_file *cur_file)
{
	char	*p;
	int		len;

	len = 0;
	if (cur_file->backup[len] == 0)
		return (0);
	while (cur_file->backup[len] && cur_file->backup[len] != '\n')
		len++;
	if (cur_file->backup[len] == '\n')
	{
		p = (char *)malloc(sizeof(char) * (len + 2));
		if (!p)
			return (0);
		ft_memcpy(p, cur_file->backup, len + 1);
	}
	else
	{
		p = (char *)malloc(sizeof(char) * (len + 1));
		if (!p)
			return (0);
		ft_memcpy(p, cur_file->backup, len);
	}
	p[++len] = '\0';
	return (p);
}

char	*update_backup(char *backup)
{
	char	*temp;
	int		i;
	int		j;		

	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (!backup[i])
	{
		free(backup);
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i +1));
	if (!temp)
		return (0);
	++i;
	j = 0;
	while (backup[i])
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	list;
	t_file			*cur_file;
	char			*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	cur_file = check_list(&list, fd);
	if (cur_file)
	{
		cur_file->backup = read_file(cur_file, fd);
		if (!cur_file->backup)
		{
			delete_list(&list, cur_file);
			return (0);
		}
		line = make_line(cur_file);
		cur_file->backup = update_backup(cur_file->backup);
	}
	delete_list(&list, cur_file);
	return (line);
}
