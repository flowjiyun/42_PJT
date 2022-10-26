/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:24:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 09:40:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	view(int keycode, t_mlx *mlx)
{
	if (keycode == P)
		mlx->var->isometric = 0;
	else if (keycode == O)
		mlx->var->isometric = 1;
	mlx->var->angle_x = 0;
	mlx->var->angle_y = 0;
	mlx->var->angle_z = 0;
	do_fdf(mlx);
}

void	exit_window(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		free(mlx->map->arr_depth);
		free(mlx->map->arr_color);
		mlx_destroy_window(mlx->display, mlx->window);
		exit(0);
	}
	do_fdf(mlx);
}
