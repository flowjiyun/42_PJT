/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_unit_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:07 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/21 16:43:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static int	get_max(t_tool *tool, int len)
{
	int		i;
	int		max;
	t_list	*cursor;

	i = 0;
	max = 0;
	cursor = tool->a_info->tail;
	while (i < len)
	{
		if (max < cursor->rank)
			max = cursor->rank;
		cursor = cursor->prev;
		i++;
	}
	return (max);
}

static int	get_min(t_tool *tool, int len)
{
	int		i;
	long	min;
	t_list	*cursor;

	i = 0;
	min = 2147483649;
	cursor = tool->a_info->tail;
	while (i < len)
	{
		if (min > cursor->rank)
			min = cursor->rank;
		cursor = cursor->prev;
		i++;
	}
	return ((int)min);
}

static void	remain_condition_a(t_tool *tool)
{
	if (tool->a_info->tail->rank > tool->a_info->tail->prev->rank)
		ra(tool);
	else
	{
		sa(tool);
		ra(tool);
	}
}

void	sort_unit_three_a(t_tool *tool, int len)
{
	int	min;
	int	max;

	min = get_min(tool, len);
	max = get_max(tool, len);
	if (min == tool->a_info->tail->prev->prev->rank)
	{
		if (tool->a_info->tail->rank < tool->a_info->tail->prev->rank)
			rra(tool);
		else
		{
			ra(tool);
			sa(tool);
		}
	}
	else if (max == tool->a_info->tail->prev->prev->rank)
	{
		if (tool->a_info->tail->rank > tool->a_info->tail->prev->rank)
			sa(tool);
	}
	else
		remain_condition_a(tool);
	return ;
}
