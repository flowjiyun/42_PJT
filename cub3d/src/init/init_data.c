/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:52:33 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/27 11:25:57by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*init_texture(t_list *list, t_mlx *mlx)
{
	t_texture	*wall;
	(void) list;
	(void) mlx;
	wall = _malloc(sizeof(t_texture) * 4);
	(wall[0]).relative_path = ft_strdup(NO);
	(wall[1]).relative_path = ft_strdup(SO);
	(wall[2]).relative_path = ft_strdup(WE);
	(wall[3]).relative_path = ft_strdup(EA);
	for (int i = 0; i < 4; ++i)
	{
		wall[i].image = _malloc(sizeof(t_image));
		wall[i].image->img = mlx_png_file_to_image(mlx->display,
				wall[i].relative_path, &wall[i].width, &wall[i].height);
		wall[i].image->addr = mlx_get_data_addr(wall[i].image->img,
				&wall[i].image->bits_per_pixel,
				&wall[i].image->size_line, &wall[i].image->endian);
	}
	return (wall);
}

static t_color	*init_color(t_list *list)
{
	t_color	*color;

	(void) list;
	color = _malloc(sizeof(t_color));
	color->floor_color = 0xcc6600;
	color->ceilling_color = 0x99ffff;
	return (color);
}

static t_map	*init_map(t_list *list)
{
	t_map	*map;

	map = _malloc(sizeof(t_map));
	map->world_map = get_array_map(list);
	map->width = get_world_map_width(map->world_map);
	map->height = get_world_map_height(map->world_map);
	return (map);
}

static t_player	*init_player(t_map *map)
{
	t_player	*player;

	player = _malloc(sizeof(t_player));
	get_player_init_pos(player, map);
	get_player_init_dir(player);
	get_player_init_plane(player);
	return (player);
}

t_data	*init_data(t_list *list, t_mlx *mlx)
{
	t_data	*data;

	data = _malloc(sizeof(t_data));
	data->wall = init_texture(list, mlx);
	data->color = init_color(list);
	data->map = init_map(list);
	data->player = init_player(data->map);
	data->mlx = mlx;
	return (data);
}
