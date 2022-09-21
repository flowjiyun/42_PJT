/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:53:59 by jiyun             #+#    #+#             */
/*   Updated: 2022/09/21 19:06:12 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"

void	print_list(t_list_info *list_info)
{
	t_list	*cursor;

	cursor = list_info->head;
	while (cursor != NULL)
	{
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
	printf("\n");
}

void	print_list_rank(t_list_info *list_info)
{
	t_list	*cursor;

	cursor = list_info->head;
	while (cursor != NULL)
	{
		printf("%d ", cursor->rank);
		cursor = cursor->next;
	}
	printf("\n");
}

void	clear_list(t_list_info *list_info)
{
	t_list	*temp;

	while (list_info->head != NULL)
	{
		temp = list_info->head->next;
		free(list_info->head);
		list_info->head = temp;
	}
}

void	swap_node(t_list_info *list_info)
{
	t_list *fixed_node;
	t_list *cursor;
	t_list *cursor_l;

	cursor = list_info->tail;
	cursor_l = cursor->prev;
	fixed_node = cursor_l->prev;
	cursor->prev = fixed_node;
	if (fixed_node != NULL)
		fixed_node->next = cursor;
	cursor->next = cursor_l;
	cursor_l->prev = cursor;
	cursor_l->next = NULL;
	if (cursor_l == list_info->head)
		list_info->head = cursor;
	list_info->tail = cursor_l;
}
