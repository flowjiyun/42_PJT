/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit_three_a_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/16 23:28:03 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static void	remain_condition_a(t_tool *tool)
{
	if (tool->a_info->tail->rank > tool->a_info->tail->prev->rank)
	{
		sa(tool);
		ra(tool);
		sa(tool);
		rra(tool);
	}
	else
	{
		ra(tool);
		sa(tool);
		rra(tool);
	}
}

static void	min_condition_a(t_tool *tool)
{
	if (tool->a_info->tail->rank < tool->a_info->tail->prev->rank)
	{
		ra(tool);
		sa(tool);
		rra(tool);
		sa(tool);
	}
	else
	{
		sa(tool);
		ra(tool);
		sa(tool);
		rra(tool);
		sa(tool);
	}
}

void	sort_unit_three_a_extra(t_tool *tool, int len)
{
	int	min;
	int	max;

	min = get_min_a(tool, len);
	max = get_max_a(tool, len);
	if (min == tool->a_info->tail->prev->prev->rank)
		min_condition_a(tool);
	else if (max == tool->a_info->tail->prev->prev->rank)
	{
		if (tool->a_info->tail->rank > tool->a_info->tail->prev->rank)
			sa(tool);
	}
	else
		remain_condition_a(tool);
	return ;
}
