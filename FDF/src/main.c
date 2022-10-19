/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:29:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/19 16:23:32 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->screen, mlx->window);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argv;

	if (argc != 2)
	{
		write(2, "ARG NUM ERROR", 13);
		exit(1);
	}
	// parse_map(char **argv);
	mlx.screen = mlx_init();
	mlx.window = mlx_new_window(mlx.screen, 500, 500, "Hello world!");
	mlx.data.img = mlx_new_image(mlx.screen, 500, 500);
	mlx.data.addr = mlx_get_data_addr(mlx.data.img, &mlx.data.bits_per_pixel, &mlx.data.line_length, &mlx.data.endian);
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			my_mlx_pixel_put(&mlx.data, i, j, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(mlx.screen, mlx.window, mlx.data.img, 50, 50);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_loop(mlx.screen);
}
