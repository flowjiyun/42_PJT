/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/21 19:20:31 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

static void	check_double(t_list_info *a_info)
{
	t_list	*cursor;
	t_list	*cur_head;

	cur_head = a_info->head;
	while (cur_head != 0)
	{
		cursor = cur_head->next;
		while (cursor != 0)
		{
			if (cur_head->data == cursor->data)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			cursor = cursor->next;
		}
		cur_head = cur_head->next;
	}
}

static int	check_sorted(t_list_info *a_info, int *answer)
{
	int		i;
	t_list	*cursor;

	i = 0;
	cursor = a_info->tail;
	while (i < a_info->len)
	{
		if (cursor->data == answer[i])
		{
			i++;
			cursor = cursor->prev;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list_info	a_info;
	t_list_info	b_info;
	int			*answer;
	t_tool		tool;

	if (argc == 1)
		exit(1);
	init_list_info(&a_info, &b_info);
	init_list(&a_info, argc, argv);
	check_double(&a_info);
	answer = init_ordered_array(&a_info);
	if (check_sorted(&a_info, answer) == 1)
		exit(1);
	parse_list(&a_info, answer);
	init_tool(&tool, &a_info, &b_info, answer);
	push_swap(&tool);
	free(answer);
	clear_list(tool.a_info);
	return (0);
}
