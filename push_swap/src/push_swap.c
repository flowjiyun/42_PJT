/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:08:02 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/15 16:31:31 by jiyunpar         ###   ########.fr       */
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

static int	slice_stack_init(t_list_info *a_info, t_list_info * b_info, int len, int median)
{
	int	push_len;
	int	count;

	push_len = 0;
	count = 0;
	while (len-- & push_len < median)
	{
		if (a_info->tail->data <= median)
		{
			pb(a_info, b_info);
			push_len++;
		}
		else
		{
			ra(a_info);
			count++;
		}
		
	}
}

void	push_swap(t_list_info *a_info, t_list_info *b_info)
{
	int	push_len;
	int	median;

	median = get_median(a_info->len);
	push_len = slice_stack_init(a_info, b_info, a_info->len, median);
	sort_stack_a(a_info, b_info, a_info->len, median);
}
