/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:53:59 by jiyun             #+#    #+#             */
/*   Updated: 2022/09/20 22:39:33 by jiyun            ###   ########.fr       */
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
	t_list	*cursor;
	t_list	*left;
	t_list	*right;

	left = list_info->tail->prev;
	right = list_info->tail;
	cursor = right;
	right->next = cursor->prev;
	right->prev = cursor->prev->prev;
	left->next = cursor->next;
	left->prev = cursor;
	if (left == list_info->head)
		list_info->head = right;
	list_info->tail = left;
}
