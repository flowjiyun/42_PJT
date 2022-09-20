/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:09:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/20 22:38:16 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	sort_unit_a(t_tool *tool, int len)
{
	if (len == 2)
	{
		if (tool->a_info->tail->rank > tool->a_info->tail->prev->rank)
			sa(tool);
		else
			return ;
	}
}

static int	get_median_a(int len, int pre_median)
{
	int	median;

	if (len == 3)
		median = pre_median + (len / 2 + 1);
	else
		median = pre_median + len / 2;
	return (median);
}

static int	get_push_len_a(int len)
{
	int	ret;

	if (len % 2 == 1)
		ret = len / 2 + 1;
	else
		ret = len / 2;
	return (ret);
}

static int	slice_stack_a(t_tool *tool, int len, int median)
{
	int	ret;
	int	count;
	int	push_len;

	count = 0;
	ret = 0;
	push_len = get_push_len_a(len);
	while (len-- && ret < push_len)
	{
		if (tool->a_info->tail->rank <= median)
		{
			pb(tool);
			ret++;
		}
		else
		{
			ra(tool);
			count++;
		}
	}
	while (count--)
		rra(tool);
	return (ret);
}

void	sort_stack_a(t_tool *tool, int len, int pre_median)
{
	int	median;
	int	push_len;
	int	remain;

	if (len <= 2)
	{
		sort_unit_a(tool, len);
		return ;
	}
	median = get_median_a(len, pre_median);
	push_len = slice_stack_a(tool, len, median);
	remain = len - push_len;
	sort_stack_a(tool, remain, median);
	sort_stack_b(tool, push_len, median);
	while (push_len--)
		pa(tool);
}
