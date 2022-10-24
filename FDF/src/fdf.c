/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/24 17:08:48 by jiyunpar         ###   ########.fr       */
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
	// printf("%d, %d, %d\n", *x, *y, *z);
	*x = prev_x * cos(M_PI / 60 * 4) - prev_y * cos(M_PI / 60 * 4);
	*y = prev_x * sin(M_PI / 60 * 4) + prev_y * sin(M_PI / 60 * 4) - *z;
}

static t_point	*project_point(t_point *point, t_var *var, t_map *map)
{
	point->x *= var->offset;
	point->y *= var->offset;
	point->z *= var->offset;
	point->x -= (map->width * var->offset) / 2;
	point->y -= (map->height * var->offset) / 2;
	rotate_x(&(point->y), &(point->z), var->angle_x);
	rotate_y(&(point->x), &(point->z), var->angle_y);
	rotate_z(&(point->x), &(point->y), var->angle_z);
	// if ()
	convert_isometric(&(point->x), &(point->y), &(point->z));
	point->x += WND_WIDTH / 2;
	point->y += WND_HEIGHT / 2;
	point->y += map->height * var->offset / 2;
	return (point);
}

static void	my_mlx_pixel_put(t_point *point, t_mlx *mlx)
{
	char	*dst;

	if ((0 <= point->x && point->x < WND_WIDTH) && (0 <= point->y && point->y < WND_HEIGHT))
	{
		dst = mlx->addr + (point->y * mlx->size_line + point->x * (mlx->bits_per_pixel / 8));
		*((unsigned int *)dst) = point->color;
	}
}

static void	init_delta_step(t_point *delta, t_point *start, t_point *end, t_point *step)
{
	delta->x = abs(end->x - start->x);
	delta->y = -abs(end->y - start->y);
	if (start->x < end->x)
		step->x = 1;
	else
		step->x = -1;
	if (start->y < end->y)
		step->y = 1;
	else
		step->y = -1;
}

static double	get_ratio(int s, int f, int cur)
{
	double	ratio;

	if (s == f)
		return (1.0);
	ratio = (double)(cur - s) / (f - s);
	return (ratio);
}

static int	process_lerp(int f, int s, double ratio)
{
	return ((int)((ratio) * s + (1 - ratio) * f));
}

/*
** quadrant 1, 4, 5, 8(delta.x > delta.y): sample by x
** quadrant 2, 3, 6, 7(delta.x < delta.y): sample by y
*/

int	get_color(t_point cur, t_point *s, t_point *f, t_point delta)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (cur.color == f->color)
		return (cur.color);
	if (delta.x > delta.y)
		ratio = get_ratio(s->x, f->x, cur.x);
	else
		ratio = get_ratio(s->y, f->y, cur.y);
	red = process_lerp((f->color >> 16) & 0xFF, (s->color >> 16) & 0xFF, ratio);
	green = process_lerp((f->color >> 8) & 0xFF, (s->color >> 8) & 0xFF, ratio);
	blue = process_lerp(f->color & 0xFF, s->color & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

static void	plot_line(t_point *start, t_point *end, t_mlx *mlx)
{
	t_point	delta;
	t_point	*cur;
	t_point	step;
	int		error[2];

	init_delta_step(&delta, start, end, &step);
	error[0] = delta.x + delta.y;
	cur = start;
	while (1)
	{
		my_mlx_pixel_put(cur, mlx);
		if (cur->x == end->x && cur->y == end->y)
			break ;
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			cur->x += step.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			cur->y += step.y;
		}
	}
	free(start);
	free(end);
}

// plotLine(int x0, int y0, int x1, int y1)
//     dx =  abs(x1-x0);
//     sx = x0<x1 ? 1 : -1;
//     dy = -abs(y1-y0);
//     sy = y0<y1 ? 1 : -1;
//     err = dx+dy;  // error value e_xy
//     while (true)   // loop
//         plot(x0, y0);
//         if (x0 == x1 && y0 == y1) break;
//         e2 = 2*err;
//         if (e2 >= dy) // e_xy+e_x > 0
//             err += dy;
//             x0 += sx;
//         end if
//         if (e2 <= dx) // e_xy+e_y < 0
//             err += dx;
//             y0 += sy;
//         end if
//     end while

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
			// my_mlx_pixel_put(project_point(get_point(x, y, map), var, map), mlx);
			if (x < map->width - 1)
				plot_line(project_point(get_point(x, y, map), var, map), project_point(get_point(x + 1, y, map), var, map), mlx);
			if (y < map->height -1)
				plot_line(project_point(get_point(x, y, map), var, map), project_point(get_point(x, y + 1, map), var, map), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->img, 0, 0);
}