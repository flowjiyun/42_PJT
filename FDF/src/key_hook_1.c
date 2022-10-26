/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:21:56 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 12:33:25 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translate(int keycode, t_mlx *mlx)
{
	if (keycode == D)
		mlx->var->x_translate += 10;
	else if (keycode == A)
		mlx->var->x_translate -= 10;
	else if (keycode == S)
		mlx->var->y_translate += 10;
	else if (keycode == W)
		mlx->var->y_translate -= 10;
}

void	rotate(int keycode, t_mlx *mlx)
{
	if (keycode == UP)
		mlx->var->angle_x += M_PI / 180.0;
	else if (keycode == DOWN)
		mlx->var->angle_x -= M_PI / 180.0;
	else if (keycode == LEFT)
		mlx->var->angle_y += M_PI / 180.0;
	else if (keycode == RIGHT)
		mlx->var->angle_y -= M_PI / 180.0;
	else if (keycode == ZERO)
		mlx->var->angle_z += M_PI / 180.0;
	else if (keycode == NINE)
		mlx->var->angle_z -= M_PI / 180.0;
}

void	zoom(int keycode, t_mlx *mlx)
{
	if (keycode == PLUS)
		mlx->var->offset *= 1.1;
	else if (keycode == MINUS)
		mlx->var->offset /= 1.1;
}

void	depth(int keycode, t_mlx *mlx)
{
	if (keycode == OPEN)
		mlx->var->z_modify += 0.05;
	else if (keycode == CLOSE)
		mlx->var->z_modify -= 0.05;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == D || keycode == A || keycode == S || keycode == W)
		translate(keycode, mlx);
	else if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == ZERO || keycode == NINE)
		rotate(keycode, mlx);
	else if (keycode == ESC)
		exit_window(keycode, mlx);
	else if (keycode == PLUS || keycode == MINUS)
		zoom(keycode, mlx);
	else if (keycode == OPEN || keycode == CLOSE)
		depth(keycode, mlx);
	else if (keycode == P || keycode == O)
		view(keycode, mlx);
	do_fdf(mlx);
	put_string_img(mlx);
	return (0);
}
