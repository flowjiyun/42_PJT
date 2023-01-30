/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:16:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/30 12:23:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_mlx	mlx;
	int		width;
	int		height;
	unsigned int *dst;

	mlx.display = mlx_init();
	mlx.window = mlx_new_window(mlx.display, 100, 100, "cub3D");
	mlx.img = mlx_png_file_to_image(mlx.display, "./texture/pics/bluestone.png", &width, &height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	printf("tex width : %d, tex height : %d\n", width, height);
	printf("img bit per pixel : %d, img size line : %d\n", mlx.bits_per_pixel, mlx.size_line);	
	dst = mlx.addr + (63 * mlx.size_line);
	// *dst = 0xffffff;
	printf("color : %u\n", *dst);
	mlx_loop(mlx.display);

	return (0);
}
