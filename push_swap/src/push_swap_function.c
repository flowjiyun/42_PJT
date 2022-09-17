/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/17 20:22:02 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	sa(t_tool *tool)
{
	swap_node_left(tool->a_info->tail, tool->a_info);
}

void	sb(t_tool *tool)
{
	swap_node_left(tool->b_info->tail, tool->b_info);
}

void	pa(t_tool *tool)
{
	t_list	*node;

	if (tool->b_info->head == NULL)
		return ;
	node = make_node(tool->b_info->tail->data);
	push_back(tool->a_info, node);
	pop_back(tool->b_info);
}

void	pb(t_tool *tool)
{
	t_list	*node;

	if (tool->a_info->head == NULL)
		return ;
	node = make_node(tool->a_info->tail->data);
	push_back(tool->b_info, node);
	pop_back(tool->a_info);
}

void	ra(t_tool *tool)
{
	tool->a_info->tail->next = tool->a_info->head;
	tool->a_info->head->prev = tool->a_info->tail;
	tool->a_info->head = tool->a_info->head->prev;
	tool->a_info->tail = tool->a_info->tail->prev;
	tool->a_info->tail->next = NULL;
	tool->a_info->head->prev = NULL;
}

void	rb(t_tool *tool)
{
	tool->b_info->tail->next = tool->b_info->head;
	tool->b_info->head->prev = tool->b_info->tail;
	tool->b_info->head = tool->b_info->head->prev;
	tool->b_info->tail = tool->b_info->tail->prev;
	tool->b_info->tail->next = NULL;
	tool->b_info->head->prev = NULL;
}

void	rra(t_tool *tool)
{
	tool->a_info->tail->next = tool->a_info->head;
	tool->a_info->head->prev = tool->a_info->tail;
	tool->a_info->head = tool->a_info->head->next;
	tool->a_info->tail = tool->a_info->tail->next;
	tool->a_info->tail->next = NULL;
	tool->a_info->head->prev = NULL;
}

void	rrb(t_tool *tool)
{
	tool->b_info->tail->next = tool->b_info->head;
	tool->b_info->head->prev = tool->b_info->tail;
	tool->b_info->head = tool->b_info->head->next;
	tool->b_info->tail = tool->b_info->tail->next;
	tool->b_info->tail->next = NULL;
	tool->b_info->head->prev = NULL;
}