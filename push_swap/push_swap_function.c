/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/08 14:43:29 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	sa(t_list_info *list_info)
{
	swap_node_left(list_info->tail, list_info);
}

void	sb(t_list_info *list_info)
{
	swap_node_left(list_info->tail, list_info);
}

void	pa(t_list_info *b_info, t_list_info *a_info)
{
	t_list	*node;

	if (b_info->head == NULL)
		return ;
	node = make_node(b_info->tail->data);
	push_back(a_info, node);
	pop_back(b_info);
}

void	pb(t_list_info *a_info, t_list_info *b_info)
{
	t_list	*node;

	if (a_info->head == NULL)
		return ;
	node = make_node(a_info->tail->data);
	push_back(b_info, node);
	pop_back(a_info);
}
