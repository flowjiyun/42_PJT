/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/26 20:26:59 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define MAP_WIDTH	9
# define MAP_HEIGHT	9

typedef struct s_mlx
{
	void	*display;
	void	*window;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

typedef struct s_texture
{
	int	width;
	int	height;
}	t_texture;
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

char	**get_array_map(t_list *list);
t_list	*read_mapfile(char **argv);
int		get_world_map_height(char **world_map);
int		get_world_map_width(char **world_map);

#endif