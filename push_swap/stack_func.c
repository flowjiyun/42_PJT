/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:11:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/25 16:26:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_node(int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	pop_back(t_list_info *list_info)
{
	t_list	*temp;

	temp = list_info->tail;
	list_info->tail = temp->prev;
	free(temp);
}

void	push_front(t_list_info *list_info, t_list *node)
{
	node->next = list_info->head;
	node->prev = NULL;
	list_info->head->prev = node;
	list_info->head = node;
}

void	push_back(t_list_info *list_info, t_list *node)
{
	node->next = NULL;
	node->prev = list_info->tail;
	list_info->tail->next = node;
	list_info->tail = node;
}
