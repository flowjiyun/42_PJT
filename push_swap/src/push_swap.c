/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:08:02 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/17 19:58:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static int	get_median_init(int len)
{
	int	median;

	if (len / 2 == 1)
		median = len / 2 + 1;
	else
		median = len / 2;
	return (median);
}

static int	get_push_len_init(int len)
{
	int	ret;

	if (len % 2 == 1)
		ret = len / 2 + 1;
	else
		ret = len / 2;
	return (ret);
}

static int	slice_stack_init(t_tool *tool, int len, int median)
{
	int	ret;
	int	count;
	int	push_len;

	ret = 0;
	count = 0;
	push_len = get_push_len_init(len);
	while (len-- && ret < push_len)
	{
		if (tool->a_info->tail->data <= median)
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

void	push_swap(t_tool *tool)
{
	int	len;
	int	push_len;
	int	median;

	len = tool->a_info->len;
	median = get_median_init(tool->a_info->len);
	push_len = slice_stack_init(tool, tool->a_info->len, median);
	sort_stack_a(tool, len - push_len, median);
	sort_stack_b(tool, push_len, median);
	while (push_len--)
		pa(tool);
}
