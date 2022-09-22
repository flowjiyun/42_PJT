/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_function_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:21:29 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/21 19:21:38 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	rb(t_tool *tool)
{
	tool->b_info->tail->next = tool->b_info->head;
	tool->b_info->head->prev = tool->b_info->tail;
	tool->b_info->head = tool->b_info->head->prev;
	tool->b_info->tail = tool->b_info->tail->prev;
	tool->b_info->tail->next = NULL;
	tool->b_info->head->prev = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_tool *tool)
{
	tool->a_info->tail->next = tool->a_info->head;
	tool->a_info->head->prev = tool->a_info->tail;
	tool->a_info->head = tool->a_info->head->next;
	tool->a_info->tail = tool->a_info->tail->next;
	tool->a_info->tail->next = NULL;
	tool->a_info->head->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_tool *tool)
{
	tool->b_info->tail->next = tool->b_info->head;
	tool->b_info->head->prev = tool->b_info->tail;
	tool->b_info->head = tool->b_info->head->next;
	tool->b_info->tail = tool->b_info->tail->next;
	tool->b_info->tail->next = NULL;
	tool->b_info->head->prev = NULL;
	write(1, "rrb\n", 4);
}
