/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit_three_b_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/16 23:39:25 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static void	remain_condition_b(t_tool *tool)
{
	if (tool->b_info->tail->rank > tool->b_info->tail->prev->rank)
	{
		rb(tool);
		sb(tool);
		rrb(tool);
	}
	else
	{
		sb(tool);
		rb(tool);
		sb(tool);
		rrb(tool);
	}
}

static void	max_condition_b(t_tool *tool)
{
	if (tool->b_info->tail->rank > tool->b_info->tail->prev->rank)
	{
		rb(tool);
		sb(tool);
		rrb(tool);
		sb(tool);
	}
	else
	{
		sb(tool);
		rb(tool);
		sb(tool);
		rrb(tool);
		sb(tool);
	}
}

void	sort_unit_three_b_extra(t_tool *tool, int len)
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
		max_condition_b(tool);
	else
		remain_condition_b(tool);
	return ;
}
