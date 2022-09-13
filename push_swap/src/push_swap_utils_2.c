/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:27:11 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 17:16:32 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

void	parse_list(t_list_info *list_info, int	*arr)
{
	int		i;
	t_list	*cursor;

	i = 0;
	while (i < list_info->len)
	{
		cursor = list_info->head;
		while (cursor != NULL)
		{
			if (arr[i] == cursor->data)
			{
				cursor->data = i + 1;
				break ;
			}
			cursor = cursor->next;
		}
		i++;
	}
}
