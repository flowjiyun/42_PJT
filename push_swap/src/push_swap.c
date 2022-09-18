/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:08:02 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/18 10:34:43 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	sort_unit_init(t_tool *tool, int len)
{
	if (len == 2)
	{
		if (tool->a_info->tail->data > tool->a_info->tail->prev->data)
			sa(tool);
	}
}

static int	get_median_init(int len)
{
	int	median;

	if (len / 2 == 1)
		median = len / 2 + 1;
	else
		median = len / 2;
	return (median);
}

static int	slice_stack_init(t_tool *tool, int len, int median)
{
	int	ret;

	ret = 0;
	while (len--)
	{
		if (tool->a_info->tail->data <= median)
		{
			pb(tool);
			ret++;
		}
		else
			ra(tool);
	}
	return (ret);
}

void	push_swap(t_tool *tool)
{
	int	len;
	int	push_len;
	int	median;

	len = tool->a_info->len;
	if (len <= 2)
	{
		sort_unit_init(tool, len);
		return ;
	}
	median = get_median_init(tool->a_info->len);
	push_len = slice_stack_init(tool, tool->a_info->len, median);
	sort_stack_a(tool, len - push_len, median);
	sort_stack_b(tool, push_len, median);
	while (push_len--)
		pa(tool);
}
