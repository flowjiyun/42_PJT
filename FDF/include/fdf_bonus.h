/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:50:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 14:04:19 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "linked_list.h"
# include "get_next_line.h"

# define WND_WIDTH 1400
# define WND_HEIGHT 1000

typedef struct s_map
{
	int	width;
	int	height;
	int	*arr_depth;
	int	*arr_color;
}	t_map;

typedef struct s_var
{
	int		x_translate;
	int		y_translate;
	int		isometric;
	double	offset;
	double	z_modify;
	double	angle_x;
	double	angle_y;
	double	angle_z;
}	t_var;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_mlx
{
	void	*display;
	void	*window;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_map	*map;
	t_var	*var;
}	t_mlx;

typedef enum e_key
{
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	LEFT = 124,
	RIGHT = 123,
	ZERO = 29,
	NINE = 25,
	PLUS = 24,
	MINUS = 27,
	OPEN = 33,
	CLOSE = 30,
	P = 35,
	O = 31
}	t_key;

/*---------------------check_file.c-----------------------*/
int		check_valid_file(char *file_path);

/*---------------------read_map.c-----------------------*/
void	read_map(char *file, t_list_info *list, t_map *map);

/*---------------------get_coordinate.c---------------------*/
void	get_coordinate(t_list_info *list, t_map *map);

/*---------------------init_struct.c-----------------------*/
void	init_mlx(t_mlx *mlx, t_map *map, t_var *var);
void	init_var(t_var *var, t_map *map);

/*---------------------rotate.c-----------------------*/
void	rotate_x(int *y, int *z, double angle_x);
void	rotate_y(int *x, int *z, double angle_y);
void	rotate_z(int *x, int *y, double angle_z);

/*---------------------fdf_bonus.c-----------------------*/
void	do_fdf(t_mlx *mlx);

/*---------------------draw_line.c-----------------------*/
void	plot_line(t_point *start, t_point *end, t_mlx *mlx);

/*---------------------put_string_bonus.c-----------------------*/
void	put_string_img(t_mlx *mlx);

/*---------------------key_hook_1_bonus.c-----------------------*/
int		key_hook(int keycode, t_mlx *mlx);
void	translate(int keycode, t_mlx *mlx);
void	rotate(int keycode, t_mlx *mlx);
void	zoom(int keycode, t_mlx *mlx);
void	depth(int keycode, t_mlx *mlx);

/*---------------------key_hook_2_bonus.c-----------------------*/
void	exit_window(int keycode, t_mlx *mlx);
void	view(int keycode, t_mlx *mlx);

/*---------------------fdf_util_1.c-----------------------*/
char	**ft_split(char const *s, char c);

/*---------------------fdf_util_2.c-----------------------*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
void	free_2d(char **data);
void	terminate(char *str);

#endif