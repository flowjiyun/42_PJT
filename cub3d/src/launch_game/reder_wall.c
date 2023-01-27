/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reder_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:59:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/27 23:19:38 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	caculate_init_dist(t_data *data, t_raycast *cur_state)
{
	if (data->player->raydir_x < 0)
	{
		cur_state->step_x = -1;
		cur_state->sidedist_x = (data->player->pos_x - cur_state->map_x)
			* cur_state->deltadist_x;
	}
	else
	{
		cur_state->step_x = 1;
		cur_state->sidedist_x = (cur_state->map_x + 1.0 - data->player->pos_x)
			* cur_state->deltadist_x;
	}
	if (data->player->raydir_y < 0)
	{
		cur_state->step_y = -1;
		cur_state->sidedist_y = (data->player->pos_y - cur_state->map_y)
			* cur_state->deltadist_y;
	}
	else
	{
		cur_state->step_y = 1;
		cur_state->sidedist_y = (cur_state->map_y + 1.0 - data->player->pos_y)
			* cur_state->deltadist_y;
	}
}

static void	init_cur_state(t_data *data, t_raycast *cur_state, int x)
{
	const t_player	*player = data->player;

	cur_state->ratio = 2 * x / (double)SCREEN_WIDTH - 1;
	cur_state->raydir_x = player->dir_x + player->plane_x * cur_state->ratio;
	cur_state->raydir_y = player->dir_y + player->plane_y * cur_state->ratio;
	cur_state->map_x = (int)player->pos_x;
	cur_state->map_y = (int)player->pos_y;
	if (cur_state->raydir_x == 0)
		cur_state->deltadist_x = 1e30;
	else
		cur_state->deltadist_x = fabs(1 / cur_state->raydir_x);
	if (cur_state->raydir_y == 0)
		cur_state->deltadist_y = 1e30;
	else
		cur_state->deltadist_y = fabs(1 / cur_state->raydir_y);
	cur_state->hit = 0;
	caculate_init_dist(data, cur_state);
}

// if side == 1, hit y = c
// if side == 0, hit x = c
static void	dda(t_data *data, t_raycast *cur_state)
{
	const char	**world_map = data->map->world_map;

	while (cur_state->hit == 0)
	{
		if (cur_state->sidedist_x < cur_state->sidedist_y)
		{
			cur_state->sidedist_x += cur_state->deltadist_x;
			cur_state->map_x += cur_state->step_x;
			cur_state->side = 0;
		}
		else
		{
			cur_state->sidedist_y += cur_state->deltadist_y;
			cur_state->map_y += cur_state->step_y;
			cur_state->side = 1;
		}
		if (world_map[cur_state->map_y][cur_state->map_x] == '1')
			cur_state->hit = 1;
	}
}

static void	raycast(t_data *data)
{
	t_raycast	cur_state;
	int			x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_cur_state(data, &cur_state, x);
		dda(data, &cur_state);
		++x;
	}
}

// draw wall to image buffer in current player state
void	render_wall(t_data *data)
{
	raycast(data);
	return ;
}
