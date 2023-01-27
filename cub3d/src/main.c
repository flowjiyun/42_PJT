/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:43:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/27 20:21:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_list		*list;
	t_mlx		*mlx;
	t_data		*data;

	errno = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Error: argnum\n", 2);
		return (1);
	}
	list = read_mapfile(argv);
	mlx = init_mlx();
	data = init_data(list, mlx);
	launch_game(data);
	free_list_node_content(list);
	// system("leaks cub3D");
	return (0);
}
