/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:17:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/30 13:50:43 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->display = mlx_init();
	mlx->window = mlx_new_window(mlx->display,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	mlx->image = _malloc(sizeof(t_image));
	mlx->image->img = mlx_new_image(mlx->display, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img,
			&mlx->image->bits_per_pixel, &mlx->image->size_line,
			&mlx->image->endian);
	return (mlx);
}
