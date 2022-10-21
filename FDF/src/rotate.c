/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:24:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 20:00:28 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate_x(int *y, int *z, double angle_x)
{
	int	prev_y;
	int	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = cos(angle_x) * prev_y - sin(angle_x) * prev_z;
	*z = sin(angle_x) * prev_y + cos(angle_x) * prev_z;
}

void	rotate_y(int *x, int *z, double angle_y)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = cos(angle_y) * prev_x + sin(angle_y) * prev_z;
	*z = -sin(angle_y) * prev_x + cos(angle_y) * prev_z;
}

void	rotate_z(int *x, int *y, double angle_z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = cos(angle_z) * prev_x - sin(angle_z) * prev_y;
	*y = sin(angle_z) * prev_x + cos(angle_z) * prev_y;
}
