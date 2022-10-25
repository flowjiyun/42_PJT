/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:16:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/25 15:43:47 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	my_mlx_pixel_put(t_point *point, t_mlx *mlx)
{
	char	*dst;

	if ((0 <= point->x && point->x < WND_WIDTH)
		&& (0 <= point->y && point->y < WND_HEIGHT))
	{
		dst = mlx->addr + (point->y * mlx->size_line
				+ point->x * (mlx->bits_per_pixel / 8));
		*((unsigned int *)dst) = point->color;
	}
}

static void	init_delta_step(t_point *delta, t_point *start,
	t_point *end, t_point *step)
{
	delta->x = abs(end->x - start->x);
	delta->y = -abs(end->y - start->y);
	if (start->x < end->x)
		step->x = 1;
	else
		step->x = -1;
	if (start->y < end->y)
		step->y = 1;
	else
		step->y = -1;
}

void	plot_line(t_point *start, t_point *end, t_mlx *mlx)
{
	t_point	delta;
	t_point	*cur;
	t_point	step;
	int		error[2];

	init_delta_step(&delta, start, end, &step);
	error[0] = delta.x + delta.y;
	cur = start;
	while (cur->x != end->x && cur->y != end->y)
	{
		my_mlx_pixel_put(cur, mlx);
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			cur->x += step.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			cur->y += step.y;
		}
	}
	free(start);
	free(end);
}
