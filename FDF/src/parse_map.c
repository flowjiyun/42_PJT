/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:54:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 13:50:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_width(char *line)
{
	char	**arr_map_line;
	int		ret;

	arr_map_line = ft_split(line, ' ');
	if (!arr_map_line)
		terminate("ERROR : SPLIT FAIL");
	ret = -1;
	while (arr_map_line[++ret])
		;
	free_2d(arr_map_line);
	return (ret);
}

static int	get_val_length(char **list)
{
	int		ret;

	ret = -1;
	while (list[++ret])
		;
	return (ret);
}

static void	make_list(char *line, t_list_info *list_info)
{
	char	**arr_map_line;
	char	**arr_map_val;
	int		i;
	t_list	*node;

	arr_map_line = ft_split(line, ' ');
	if (!arr_map_line)
		terminate("ERROR : SPLIT FAIL");
	i = -1;
	while (arr_map_line[++i])
	{
		arr_map_val = ft_split(arr_map_line[i], ',');
		if (!arr_map_val)
			terminate("ERROR : SPLIT FAIL");
		if (get_val_length(arr_map_val) == 1)
		{
			node = make_node(arr_map_val[0], NULL);
			push_back(list_info, node);
		}
		else
		{
			node = make_node(arr_map_val[0], arr_map_val[1]);
			push_back(list_info, node);
		}
		free(arr_map_val);
	}
	// printf("%d\n", i);
	free_2d(arr_map_line);
}

void	read_map(char *file, t_list_info *list, t_map *map)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		terminate("ERROR : FILE OPEN FAIL");
	line_count = 0;
	while (1)
	{
		line = get_next_line_short(fd);
		if (!line)
			break ;
		// printf("%s\n", line);
		if (line_count == 0)
			map->width = get_map_width(line);
		line[ft_strlen(line) - 1] = 0;
		make_list(line, list);
		free(line);
		line_count ++;
	}
	map->height = line_count;
	close(fd);
}
