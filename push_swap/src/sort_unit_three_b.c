/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/16 23:21:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

int	get_max_b(t_tool *tool, int len)
{
	int		i;
	int		max;
	t_list	*cursor;

	i = 0;
	max = 0;
	cursor = tool->b_info->tail;
	while (i < len)
	{
		if (max < cursor->rank)
			max = cursor->rank;
		cursor = cursor->prev;
		i++;
	}
	return (max);
}

int	get_min_b(t_tool *tool, int len)
{
	int		i;
	long	min;
	t_list	*cursor;

	i = 0;
	min = 2147483649;
	cursor = tool->b_info->tail;
	while (i < len)
	{
		if (min > cursor->rank)
			min = cursor->rank;
		cursor = cursor->prev;
		i++;
	}
	return ((int)min);
}

static void	remain_condition_b(t_tool *tool)
{
	if (tool->b_info->tail->rank > tool->b_info->tail->prev->rank)
	{
		sb(tool);
		rb(tool);
	}
	else
		rb(tool);
}

void	sort_unit_three_b(t_tool *tool, int len)
{
	int	min;
	int	max;

	min = get_min_b(tool, len);
	max = get_max_b(tool, len);
	if (min == tool->b_info->tail->prev->prev->rank)
	{
		if (tool->b_info->tail->rank < tool->b_info->tail->prev->rank)
			sb(tool);
	}
	else if (max == tool->b_info->tail->prev->prev->rank)
	{
		if (tool->b_info->tail->rank > tool->b_info->tail->prev->rank)
			rrb(tool);
		else
		{
			sb(tool);
			rrb(tool);
		}
	}
	else
		remain_condition_b(tool);
	return ;
}
