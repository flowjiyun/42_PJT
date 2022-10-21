/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 20:04:30 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// 0. get 2 point to draw line
// 1. Apply offset to point via. map size
// 2. change 3d coordinate with angle
// 3. projection to 2d(isometric view)
// 4. draw line with converted 2 point
//		->bresenham algorithm

static t_point	*get_point(int x, int y, t_map *map)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		terminate("ERROR : POINT INIT FAIL");
	point->x = x;
	point->y = y;
	i = map->width * y + x;
	point->z = map->arr_depth;
	if (map->arr_color == -1)
		point->color = 0xFFFFFF;
	else
		point->color = map->arr_color[i];
	return (point);
}

static t_point	*project_point(t_point *point, t_var *var)
{
	point->x *= var->offset;
	point->y *= var->offset;
	point->z *= var->offset;
	rotate_x(&(point->y), &(point->z), var->angle_x);
	rotate_y(&(point->x), &(point->z), var->angle_y);
	rotate_z(&(point->x), &(point->y), var->angle_z);
	return (point);
}

void	do_fdf(t_mlx *mlx, t_list_info *list, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{

			x++;
		}
		y++;

	}
}
