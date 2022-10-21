/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:01:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 13:12:52 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_atoi_short(char *str)
{
	int	val;
	int	sign;
	int	i;

	val = 0;
	sign = 1;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	return (val * sign);
}

static int	ft_atoi_hex(char *str)
{
	int	val;
	int	i;

	val = 0;
	i = 2;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = val * 16 + str[i] - '0';
		else
			val = val * 16 + (str[i] - 'A' + 10);
		i++;
	}
	return (val);
}

void	get_coordinate(t_list_info *list, t_map *map)
{
	int		*depth;
	int		*color;
	t_list	*cur;
	int		i;

	depth = (int *)malloc(sizeof(int) * map->width * map->height);
	if (!depth)
		terminate("ERROR : MALLOC");
	color = (int *)malloc(sizeof(int) * map->width * map->height);
	if (!color)
		terminate("ERROR : MALLOC");
	i = 0;
	cur = list->head;
	while (cur)
	{
		depth[i] = ft_atoi_short(cur->content_1);
		if (cur->content_2 == NULL)
			color[i] = -1;
		else
			color[i] = ft_atoi_hex(cur->content_2);
		i++;
		cur = cur->next;
	}
	map->arr_depth = depth;
	map->arr_color = color;
}
