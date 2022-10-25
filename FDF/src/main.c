/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:29:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/25 17:18:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	translate(int keycode, t_mlx *mlx)
{
	if (keycode == D)
		mlx->var->x_translate += 10;
	else if (keycode == A)
		mlx->var->x_translate -= 10;
	else if (keycode == S)
		mlx->var->y_translate += 10;
	else if (keycode == W)
		mlx->var->y_translate -= 10;
	do_fdf(mlx);
}

static void	rotate(int keycode, t_mlx *mlx)
{
	if (keycode == UP)
		mlx->var->angle_x += M_PI / 180.0;
	else if (keycode == DOWN)
		mlx->var->angle_x -= M_PI / 180.0;
	else if (keycode == LEFT)
		mlx->var->angle_y += M_PI / 180.0;
	else if (keycode == RIGHT)
		mlx->var->angle_y -= M_PI / 180.0;
	do_fdf(mlx);
}

static void	exit_window(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->display, mlx->window);
		exit(0);
	}
	do_fdf(mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == D || keycode == A || keycode == S || keycode == W)
		translate(keycode, mlx);
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		rotate(keycode, mlx);
	else if (keycode == ESC)
		exit_window(keycode, mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_list_info	list;
	t_map		map;
	t_var		var;

	errno = 0;
	if (argc != 2)
		terminate("ERROR : BAD ARG NUM\n./fdf [file].fdf");
	if (check_valid_file(argv[1]))
		terminate("ERROR : BAD FILE TYPE\n./fdf [file].fdf");
	init_list(&list, 0);
	read_map(argv[1], &list, &map);
	get_coordinate(&list, &map);
	init_var(&var, &map);
	init_mlx(&mlx, &map, &var);
	do_fdf(&mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_loop(mlx.display);
	clear_list(&list);
	return (0);
}
