/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:18:35 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 13:18:05 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf_bonus.h"

void	put_string_img(t_mlx *mlx)
{
	mlx_string_put(mlx->display, mlx->window, 20, 20, 0xFFFFFF,
		"ROTATION : UP / DOWN / LEFT / RIGHT / 0 / 9");
	mlx_string_put(mlx->display, mlx->window, 20, 40, 0xFFFFFF,
		"TRANSLATION : W / A / S / D");
	mlx_string_put(mlx->display, mlx->window, 20, 60, 0xFFFFFF,
		"ZOOM : + / -");
	mlx_string_put(mlx->display, mlx->window, 20, 80, 0xFFFFFF,
		"VIEW : O / P");
	mlx_string_put(mlx->display, mlx->window, 20, 100, 0xFFFFFF,
		"DEPTH : [ / ]");
}
