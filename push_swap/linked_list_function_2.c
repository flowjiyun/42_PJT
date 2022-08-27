/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:53:59 by jiyun             #+#    #+#             */
/*   Updated: 2022/08/27 17:38:38 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	print_list(t_list_info *list_info)
{
	t_list	*cursor;

	cursor = list_info->head;
	while (cursor != NULL)
	{
		printf("%d\n", cursor->data);
		cursor = cursor->next;
	}
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

static void	node_init(t_list *node, t_node_info *node_info)
{
	if (node != NULL)
		node_info->cursor = node;
	else
		node_info->cursor = NULL;
	if (node->next != NULL)
	{
		node_info->cursor_r = node->next;
		if (node->next->next != NULL)
			node_info->cursor_rr = node->next->next;
		else
			node_info->cursor_rr = NULL;
	}
	else
		node_info->cursor_r = NULL;
	if (node->prev != NULL)
	{
		node_info->cursor_l = node->prev;
		if (node->prev->prev != NULL)
			node_info->cursor_ll = node->prev->prev;
		else
			node_info->cursor_ll = NULL;
	}
	else
		node_info->cursor_l = NULL;
}

//특정 위치의 리스트 값끼리 swap
// 오른쪽 노드와 교환
void	swap_node_right(t_list *node, t_list_info *list_info)
{
	t_node_info	node_info;

	node_init(node, &node_info);
	if (!node_info.cursor || !node_info.cursor_r)
		return ;
	if (list_info->head == node_info.cursor)
		list_info->head = node_info.cursor_r;
	node_info.cursor->next = node_info.cursor_rr;
	node_info.cursor->prev = node_info.cursor_r;
	node_info.cursor_r->next = node_info.cursor;
	node_info.cursor_r->prev = node_info.cursor_l;
	if (node_info.cursor_rr != NULL)
		node_info.cursor_rr->prev = node_info.cursor;
	if (node_info.cursor_l != NULL)
		node_info.cursor_l->next = node_info.cursor_r;
}

// 왼쪽 노드와 교환
void	swap_node_left(t_list *node, t_list_info *list_info)
{
	t_node_info	node_info;

	node_init(node, &node_info);
	if (!node_info.cursor || !node_info.cursor_l)
		return ;
	if (list_info->head == node_info.cursor_l)
		list_info->head = node_info.cursor;
	node_info.cursor->next = node_info.cursor_l;
	node_info.cursor->prev = node_info.cursor_ll;
	node_info.cursor_l->next = node_info.cursor_r;
	node_info.cursor_l->prev = node_info.cursor;
	if (node_info.cursor_ll != NULL)
		node_info.cursor_ll->next = node_info.cursor;
	if (node_info.cursor_r != NULL)
		node_info.cursor_r->prev = node_info.cursor_l;
}