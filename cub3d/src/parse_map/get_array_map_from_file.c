/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_map_from_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:16:49 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/26 20:23:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*read_mapfile(char **argv)
{
	t_list	*list;
	char	*line;	
	int		fd;

	list = init_list();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_terminate("open");
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		push_back(list, make_node(line));
	}
	return (list);
}

char	**get_array_map(t_list *list)
{
	char	**ret;
	t_node	*cur_node;
	int		i;

	ret = _malloc(sizeof(char *) * (list->len + 1));
	i = 0;
	cur_node = list->head;
	while (cur_node)
	{
		ret[i++] = ft_strdup(cur_node->content);
		cur_node = cur_node->next;
	}
	ret[i] = NULL;
	return (ret);
}
