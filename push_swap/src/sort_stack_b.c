/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:09:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/20 22:38:15 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static void	sort_unit_b(t_tool *tool, int len)
{
	if (len == 2)
	{
		if (tool->b_info->tail->rank < tool->b_info->tail->prev->rank)
			sb(tool);
		else
			return ;
	}
}

static int	get_median_b(int len, int pre_median)
{
	int	median;

	median = pre_median - len / 2;
	return (median);
}

static int	get_push_len_b(int len)
{
	int	ret;

	ret = len / 2 + 1;
	return (ret);
}

static int	slice_stack_b(t_tool *tool, int len, int median)
{
	int	ret;
	int	count;
	int	push_len;

	count = 0;
	ret = 0;
	push_len = get_push_len_b(len);
	while (len-- && ret < push_len)
	{
		if (tool->b_info->tail->rank > median)
		{
			pa(tool);
			ret++;
		}
		else
		{
			rb(tool);
			count++;
		}
	}
	while (count--)
		rrb(tool);
	return (ret);
}

void	sort_stack_b(t_tool *tool, int len, int pre_median)
{
	int	median;
	int	push_len;
	int	remain;

	if (len <= 2)
	{
		sort_unit_b(tool, len);
		return ;
	}
	median = get_median_b(len, pre_median);
	push_len = slice_stack_b(tool, len, median);
	remain = len - push_len;
	sort_stack_a(tool, push_len, median);
	sort_stack_b(tool, remain, median);
	while (push_len--)
		pb(tool);
}
