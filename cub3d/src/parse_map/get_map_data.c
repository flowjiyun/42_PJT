/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:18:01 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/26 20:18:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_world_map_height(char **world_map)
{
	int	i;

	i = 0;
	while (world_map[i])
		++i;
	return (i);
}

int	get_world_map_width(char **world_map)
{
	int	i;

	i = 0;
	while (world_map[0][i])
		++i;
	return (i);
}