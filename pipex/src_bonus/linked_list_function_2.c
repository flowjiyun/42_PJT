/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_function_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:53:59 by jiyun             #+#    #+#             */
/*   Updated: 2022/10/08 16:33:34 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	do_free(t_list *list)
{
	int		i;
	char	**cur_content;

	i = 0;
	cur_content = list->content;
	while (cur_content[i] != NULL)
	{
		free(cur_content[i]);
		i++;
	}
	free(cur_content);
}

void	clear_list(t_list_info *list_info)
{
	t_list	*temp;

	while (list_info->head != NULL)
	{
		temp = list_info->head->next;
		if (list_info->flag == 1)
			do_free(list_info->head);
		else
			free(list_info->head->content);
		free(list_info->head);
		list_info->head = temp;
	}
}

void	swap_node(t_list_info *list_info)
{
	t_list	*fixed_node;
	t_list	*cursor;
	t_list	*cursor_l;

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

void	init_list(t_list_info *list_info, int flag)
{
	list_info->head = NULL;
	list_info->tail = NULL;
	list_info->len = 0;
	list_info->flag = flag;
}
