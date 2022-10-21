/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 14:04:26 by jiyunpar         ###   ########.fr       */
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
		terminate("ERROR : MLZ INITIALIZE");
}
