/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:35:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/17 19:08:06 by jiyunpar         ###   ########.fr       */
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

	if (!cur_file)
		return ;
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
		free(cur_file->backup);
		free(cur_file);
	}
}

char	*read_file(t_file *cur_file, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	byte;

	buf[0] = '\0';
	temp = cur_file->backup;
	while (ft_strchr(buf, '\n') == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == ERROR || byte == 0)
			return (0);
		temp = ft_strjoin(temp, buf);
	}
	return (temp);
}

char	*make_line(char *backup)
{
	char	*p;
	int		i;
	int		len;

	if (!backup)
		return (0);
	len = 0;
	while (backup[len] != '\n' && len < BUFFER_SIZE)
		len++;
	p = (char *)malloc(sizeof(char) * (len + 2));
	if (!p)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i] = backup[i];
		i++;
	}
	p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*update_backup(char *backup)
{
	char			*temp;
	int				i;
	unsigned int	start;

	if (!backup)
		return (0);
	i = 0;
	while (backup[i] != '\n')
		i++;
	start = i + 1;
	temp = ft_substr(backup, start, BUFFER_SIZE - i - 1);
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
		line = make_line(cur_file->backup);
		cur_file->backup = update_backup(cur_file->backup);
	}
	delete_list(&list, cur_file);
	return (line);
}
