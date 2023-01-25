/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:17:08 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/25 21:21:49 by jiyunpar         ###   ########.fr       */
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

// typedef struct s_player
// {

// }	t_player;

#endif