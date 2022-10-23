/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/23 22:06:27 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// 0. get 2 point to draw line ok
// 1. Apply offset to point via. map size ok
// 2. change 3d coordinate with angle ok
// 3. projection to 2d(isometric view)
// 4. draw line with converted 2 point
//		->bresenham algorithm
// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)'
// α = 30 degree
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
	point->z = map->arr_depth[i];
	if (map->arr_color[i] == -1)
		point->color = 0xFFFFFF;
	else
		point->color = map->arr_color[i];
	return (point);
}

static void	convert_isometric(int *x, int *y, int *z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(M_PI / 60) + prev_y * cos(M_PI / 60);
	*y = prev_x * sin(M_PI / 60) - prev_y * sin(M_PI / 60) - *z;
}

static t_point	*project_point(t_point *point, t_var *var, t_map *map)
{
	point->x *= var->offset;
	point->y *= var->offset;
	point->z *= var->offset / 5;
	point->x -= (map->width * var->offset) / 2;
	point->y -= (map->height * var->offset) / 2;
	rotate_x(&(point->y), &(point->z), var->angle_x);
	rotate_y(&(point->x), &(point->z), var->angle_y);
	rotate_z(&(point->x), &(point->y), var->angle_z);
	convert_isometric(&(point->x), &(point->y), &(point->z));
	point->x += WND_WIDTH / 2;
	point->y += WND_HEIGHT / 2;
	point->y += map->height * var->offset / 2;
	printf("%d, %d, %d\n", point->x, point->y, point->z);
	return (point);
}

static void	my_mlx_pixel_put(t_point *point, t_mlx *mlx)
{
	char	*dst;

	if ((0 <= point->x && point->x < WND_WIDTH) && (0 <= point->y && point->y <= WND_HEIGHT))
	{
		dst = mlx->addr + (point->y * mlx->size_line + point->x * (mlx->bits_per_pixel / 8));
		*((unsigned int *)dst) = point->color;
	}
}

void	do_fdf(t_mlx *mlx, t_map *map, t_var *var)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			my_mlx_pixel_put(project_point(get_point(x, y, map), var, map), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->img, 0, 0);
}
