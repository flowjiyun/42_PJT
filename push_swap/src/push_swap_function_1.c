/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/21 19:31:01 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	sa(t_tool *tool)
{
	swap_node(tool->a_info);
	write(1, "sa\n", 3);
}

void	sb(t_tool *tool)
{
	swap_node(tool->b_info);
	write(1, "sb\n", 3);
}

void	pa(t_tool *tool)
{
	t_list	*node;

	if (tool->b_info->head == NULL)
		return ;
	node = make_node(tool->b_info->tail->data, tool->b_info->tail->rank);
	push_back(tool->a_info, node);
	pop_back(tool->b_info);
	write(1, "pa\n", 3);
}

void	pb(t_tool *tool)
{
	t_list	*node;

	if (tool->a_info->head == NULL)
		return ;
	node = make_node(tool->a_info->tail->data, tool->a_info->tail->rank);
	push_back(tool->b_info, node);
	pop_back(tool->a_info);
	write(1, "pb\n", 3);
}

void	ra(t_tool *tool)
{
	tool->a_info->tail->next = tool->a_info->head;
	tool->a_info->head->prev = tool->a_info->tail;
	tool->a_info->head = tool->a_info->head->prev;
	tool->a_info->tail = tool->a_info->tail->prev;
	tool->a_info->tail->next = NULL;
	tool->a_info->head->prev = NULL;
	write(1, "ra\n", 3);
}
