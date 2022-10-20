/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:29:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/20 14:55:39 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	// t_mlx		mlx;
	t_list_info	list;
	t_map		map;
	// t_list		*cur;

	errno = 0;
	if (argc != 2)
		terminate("ERROR : BAD ARG NUM\n./fdf [file].fdf");
	if (check_valid_file(argv[1]))
		terminate("ERROR : BAD FILE TYPE\n./fdf [file].fdf");
	init_list(&list, 0);
	read_map(argv[1], &list, &map);
	// printf("%d, %d\n", map.width, map.height);
	// cur = list.head;
	// while (cur)
	// {
	// 	printf("%s, %s\n", cur->content_1, cur->content_2);
	// 	cur = cur->next;
	// }
	clear_list(&list);
	return (0);
}
