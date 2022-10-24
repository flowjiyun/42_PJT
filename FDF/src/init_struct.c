/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/24 14:38:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->display = mlx_init();
	if (!mlx->display)
		terminate("ERROR : MLX INITIALIZE");
	mlx->window = mlx_new_window(mlx->display, WND_WIDTH, WND_HEIGHT, "fdf");
	if (!mlx->window)
		terminate("ERROR : MLX INITIALIZE");
	mlx->img = mlx_new_image(mlx->display, WND_WIDTH, WND_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->addr)
		terminate("ERROR : MLX INITIALIZE");
}

void	init_var(t_var *var, t_map *map)
{
	double	offset_x;
	double	offset_y;

	offset_x = WND_WIDTH / map->width / 2;
	offset_y = WND_HEIGHT / map->height / 2;
	var->offset = (int)fmin(offset_x, offset_y);
	var->angle_x = 0;
	var->angle_y = 0;
	var->angle_z = 0;
}
