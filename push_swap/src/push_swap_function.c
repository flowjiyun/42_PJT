/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 16:40:22 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

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

void	ra(t_list_info *list_info)
{
	list_info->tail->next = list_info->head;
	list_info->head->prev = list_info->tail;
	list_info->head = list_info->head->prev;
	list_info->tail = list_info->tail->prev;
	list_info->tail->next = NULL;
	list_info->head->prev = NULL;
}

void	rb(t_list_info *list_info)
{
	list_info->tail->next = list_info->head;
	list_info->head->prev = list_info->tail;
	list_info->head = list_info->head->prev;
	list_info->tail = list_info->tail->prev;
	list_info->tail->next = NULL;
	list_info->head->prev = NULL;
}

void	rra(t_list_info *list_info)
{
	list_info->tail->next = list_info->head;
	list_info->head->prev = list_info->tail;
	list_info->head = list_info->head->next;
	list_info->tail = list_info->tail->next;
	list_info->tail->next = NULL;
	list_info->head->prev = NULL;
}

void	rrb(t_list_info *list_info)
{
	list_info->tail->next = list_info->head;
	list_info->head->prev = list_info->tail;
	list_info->head = list_info->head->next;
	list_info->tail = list_info->tail->next;
	list_info->tail->next = NULL;
	list_info->head->prev = NULL;
}