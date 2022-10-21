/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:50:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 19:06:39 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
// # include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "linked_list.h"

# define WND_WIDTH 1080
# define WND_HEIGHT 500

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
	int	*arr_depth;
	int	*arr_color;
}	t_map;

typedef struct s_var
{
	int	offset;
}	t_var;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

int		check_valid_file(char *file_path);
void	read_map(char *file, t_list_info *list, t_map *map);
void	get_coordinate(t_list_info *list, t_map *map);
void	init_mlx(t_mlx *mlx);
void	init_var(t_var *var, t_map *map);

char	*get_next_line_short(int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
void	free_2d(char **data);
void	terminate(char *str);

#endif