/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:24:18 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 13:04:56 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	exit_window(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		free(mlx->map->arr_depth);
		free(mlx->map->arr_color);
		mlx_destroy_window(mlx->display, mlx->window);
		exit(0);
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		exit_window(keycode, mlx);
	return (0);
}
