/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/03 22:04:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_file	*check_list(t_list *list, int fd)
{
	t_file	*new_file;
	t_file	*last_file;

	new_file = list->head;
	while (new_file)
	{
		if (new_file->fd == fd)
			return (new_file);
		last_file = new_file;
		new_file = new_file->next;
	}
	new_file = (t_file *)malloc(sizeof(t_file));
	if (new_file)
	{
		new_file->backup = NULL;
		new_file->flag = BUFFER_SIZE;
		new_file->next = NULL;
		(list->len)++;
	}
	if (list->len <= 1)
		list->head = new_file;
	else
		last_file->next = new_file;
	return (new_file);
}

void	delete_list(t_list *list, t_file *cur_file)
{
}

char	*read_file(t_file *cur_file, char **line, int fd)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	cur_file->flag = read(fd, buf, BUFFER_SIZE);
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
	}
	delete_list(&list, cur_file);
	return (line);
}
