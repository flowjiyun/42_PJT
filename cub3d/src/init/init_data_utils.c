/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:19:12 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/30 13:47:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

void	get_player_init_pos(t_player *player, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_dir(map->world_map[y][x]) == true)
			{
				player->init_state = map->world_map[y][x];
				player->pos_x = (double)x;
				player->pos_y = (double)y;
			}
			++x;
		}
		++y;
	}
}

void	get_player_init_dir(t_player *player)
{
	if (player->init_state == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
	}
	else if (player->init_state == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
	}
	else if (player->init_state == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
	}
	else
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
	}
}

void	get_player_init_plane(t_player *player)
{
	if (player->init_state == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (player->init_state == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (player->init_state == 'W')
	{
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
	else
	{
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
}
