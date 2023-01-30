/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/27 15:46:09:24jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define SCREEN_WIDTH	640
# define SCREEN_HEIGHT	480
# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define NO "./texture/bluestone.png"
# define SO "./texture/colorstone.png"
# define WE "./texture/eagle.png"
# define EA "./texture/greystone.png"

typedef struct s_image		t_image;
typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_color		t_color;
typedef struct s_player		t_player;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;
typedef struct s_mlx
{
	void	*display;
	void	*window;
	t_image	*image;
}	t_mlx;

typedef struct s_texture
{
	char	*relative_path;
	int		width;
	int		height;
	t_image	*image;
}	t_texture;

typedef struct s_color
{
	int	floor_color;
	int	ceilling_color;
}	t_color;

typedef struct s_map
{
	char	**world_map;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{	
	char	init_state;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
}	t_player;

typedef struct s_raycast
{
	double	ratio;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}	t_raycast;

typedef struct s_data
{
	t_texture	*wall;
	t_color		*color;
	t_map		*map;
	t_player	*player;
	t_mlx		*mlx;
}	t_data;

char	**get_array_map(t_list *list);
t_list	*read_mapfile(char **argv);
int		get_world_map_height(char **world_map);
int		get_world_map_width(char **world_map);

void	free_list_node_content(t_list *list);
void	free_2d_array_content(char **array);

t_data	*init_data(t_list *list, t_mlx *mlx);
void	get_player_init_pos(t_player *player, t_map *map);
void	get_player_init_dir(t_player *player);
void	get_player_init_plane(t_player *player);
t_mlx	*init_mlx(void);
void	launch_game(t_data *data);
void	render_wall(t_data *data);

#endif