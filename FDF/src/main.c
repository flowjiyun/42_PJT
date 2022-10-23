/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:29:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/23 19:01:09 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	key_hook(int keycode, t_mlx *mlx)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(mlx->screen, mlx->window);
// 		exit(0);
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_list_info	list;
	t_map		map;
	t_var		var;
	t_list		*cur;
	int i = 0;

	errno = 0;
	if (argc != 2)
		terminate("ERROR : BAD ARG NUM\n./fdf [file].fdf");
	if (check_valid_file(argv[1]))
		terminate("ERROR : BAD FILE TYPE\n./fdf [file].fdf");
	init_list(&list, 0);
	read_map(argv[1], &list, &map);
	get_coordinate(&list, &map);
	init_mlx(&mlx);
	init_var(&var, &map);
	do_fdf(&mlx, &map, &var);
	printf("%d\n", var.offset);
	for (int i = 0; i < map.width * map.height; i++)
	{
		printf("%d,%d\n", map.arr_depth[i], map.arr_color[i]);
	}
	printf("%d,%d\n", map.width, map.height);
	cur = list.head;
	while (cur)
	{
		printf("%s,%s\n", (char *)cur->content_1, (char *)cur->content_2);
		cur = cur->next;
		i++;
	}
	printf("%d\n", i);
	mlx_loop(mlx.display);
	clear_list(&list);
	return (0);
}
