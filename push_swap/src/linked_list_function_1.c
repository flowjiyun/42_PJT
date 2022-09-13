/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:11:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 16:41:47 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"

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

void	pop_front(t_list_info *list_info)
{
	t_list	*cursor;

	cursor = list_info->head;
	list_info->head = cursor->next;
	list_info->len--;
	free(cursor);
}

void	pop_back(t_list_info *list_info)
{
	t_list	*cursor;

	cursor = list_info->tail;
	list_info->tail = cursor->prev;
	list_info->tail->next = cursor->next;
	list_info->len--;
	free(cursor);
}

void	push_front(t_list_info *list_info, t_list *node)
{
	node->next = list_info->head;
	node->prev = NULL;
	if (list_info->head == NULL)
	{
		list_info->head = node;
		list_info->tail = node;
	}
	else
	{
		list_info->head->prev = node;
		list_info->head = node;
	}
	list_info->len++;
}

void	push_back(t_list_info *list_info, t_list *node)
{
	node->next = NULL;
	node->prev = list_info->tail;
	if (list_info->head == NULL)
	{
		list_info->head = node;
		list_info->tail = node;
	}
	else
	{
		list_info->tail->next = node;
		list_info->tail = node;
	}
	list_info->len++;
}
