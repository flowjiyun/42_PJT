/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/25 16:14:10 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_mlx(t_mlx *mlx, t_map *map, t_var *var)
{
	mlx->display = mlx_init();
	if (!mlx->display)
		terminate("ERROR : MLX INITIALIZE");
	mlx->window = mlx_new_window(mlx->display, WND_WIDTH, WND_HEIGHT, "fdf");
	if (!mlx->window)
		terminate("ERROR : MLX INITIALIZE");
	mlx->img = NULL;
	mlx->map = map;
	mlx->var = var;
}

void	init_var(t_var *var, t_map *map)
{
	double	offset_x;
	double	offset_y;

	offset_x = WND_WIDTH / map->width / 2;
	offset_y = WND_HEIGHT / map->height / 2;
	var->offset = (int)fmin(offset_x, offset_y);
	var->x_translate = 0;
	var->y_translate = 0;
	var->z_modify = 1;
	var->angle_x = 0;
	var->angle_y = 0;
	var->angle_z = 0;
}
