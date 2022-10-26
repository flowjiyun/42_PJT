/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 14:14:05 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

static t_point	*get_point(int x, int y, t_mlx *mlx)
{
	t_point	*point;
	int		i;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		terminate("ERROR : POINT INIT FAIL");
	point->x = x;
		point->y = y;
	i = mlx->map->width * y + x;
	point->z = mlx->map->arr_depth[i];
	if (mlx->map->arr_color[i] == -1)
		point->color = 0xFFFFFF;
	else
		point->color = mlx->map->arr_color[i];
	return (point);
}

static void	convert_isometric(int *x, int *y, int *z)
{
	int		prev_x;
	int		prev_y;
	double	alpha;

	alpha = M_PI / 60 * 4;
	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(alpha) - prev_y * cos(alpha);
	*y = prev_x * sin(alpha) + prev_y * sin(alpha) - *z;
}

static t_point	*project_point(t_point *point, t_mlx *mlx)
{
	point->x *= mlx->var->offset;
	point->y *= mlx->var->offset;
	point->z *= mlx->var->offset;
	point->z /= mlx->var->z_modify;
	point->x -= (mlx->map->width * mlx->var->offset) / 2;
	point->y -= (mlx->map->height * mlx->var->offset) / 2;
	rotate_x(&(point->y), &(point->z), mlx->var->angle_x);
	rotate_y(&(point->x), &(point->z), mlx->var->angle_y);
	rotate_z(&(point->x), &(point->y), mlx->var->angle_z);
	if (mlx->var->isometric == 0)
		convert_isometric(&(point->x), &(point->y), &(point->z));
	point->x += (WND_WIDTH / 2 + mlx->var->x_translate);
	point->y += (WND_HEIGHT / 2 + mlx->var->y_translate);
	point->y += mlx->map->height * mlx->var->offset / 2;
	return (point);
}

void	do_fdf(t_mlx *mlx)
{
	int	x;
	int	y;

	if (mlx->img)
		mlx_destroy_image(mlx->display, mlx->img);
	mlx->img = mlx_new_image(mlx->display, WND_WIDTH, WND_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x < mlx->map->width - 1)
				plot_line(project_point(get_point(x, y, mlx), mlx),
					project_point(get_point(x + 1, y, mlx), mlx), mlx);
			if (y < mlx->map->height -1)
				plot_line(project_point(get_point(x, y, mlx), mlx),
					project_point(get_point(x, y + 1, mlx), mlx), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->display, mlx->window, mlx->img, 0, 0);
}
