/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:29:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/12/26 08:20:32 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	clear_list(&list);
	init_var(&var, &map);
	init_mlx(&mlx, &map, &var);
	do_fdf(&mlx);
	mlx_hook(mlx.window, 17, 0, win_close, &mlx);
	mlx_key_hook(mlx.window, key_hook, &mlx);
	mlx_loop(mlx.display);
	return (0);
}
