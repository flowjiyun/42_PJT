/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:09:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/15 16:31:40 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static int	get_median(t_list_info *list_info, int median)
{
	if (list_info->len % 2 == 0)
		median = median + (list_info->len / 2);
	else
		median = median + (list_info->len / 2 + 1);
	return (median);
}

static void	sort_min_list_a(t_list_info *list_info)
{
	if (list_info->len == 1)
		return ;
	else
	{
		if (list_info->tail->data > list_info->tail->prev->data)
			sa(list_info);
		else
			return ;
	}
}

void	sort_a(t_list_info *a_info, t_list_info *b_info, int median)
{
	int	len;

	if (a_info->len <= 2)
	{
		sort_min_list_a(a_info);
		return ;
	}
	median = get_median(a_info, median);
	len = a_info->len;
	while (len--)
	{
		if (a_info->tail->data <= median)
			pb(a_info, b_info);
		else
			ra(a_info);
	}
	sort_a(a_info, b_info, median);
}
