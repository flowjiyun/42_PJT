/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:09:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 18:03:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static int	get_median(int start, int end)
{
	int	median;

	median = (start + end) / 2;
	return (median);
}

void	sort_min_list_a(t_list_info *list_info)
{
	if (list_info == 1)
		return ;
	else
	{
		if (list_info->tail->data > list_info->tail->prev->data)
			sa(list_info);
		else
			return ;
	}
}

void	sort_a(t_list_info *a_info, t_list_info *b_info, int start, int end)
{
	int	median;

	if (a_info->len <= 2)
	{
		sort_min_list_a(a_info);
		return ;
	}
	median = get_median(start, end);
	while (a_info->len--)
	{
		if (a_info->tail < median)
			pb(a_info, b_info);
		ra(a_info);
	}
}

void	push_swap(t_list_info *a_info, t_list_info *b_info)
{
}
