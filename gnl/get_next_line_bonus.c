/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/04 18:41:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		cur_file->flag = BUFFER_SIZE;
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
}

char	*read_file(t_file *cur_file, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	byte;

	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if ()
	}
	return (tmp);
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
		cur_file->backup = read_file(fd, cur_file);
	}
	delete_list(&list, cur_file);
	return (line);
}
