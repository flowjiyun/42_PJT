/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:27:11 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/20 22:38:23 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	if (end <= start + 1)
		return ;
	pivot = arr[start];
	left = start + 1;
	right = end - 1;
	while (1)
	{
		while (left <= right && arr[left] <= pivot)
			left++;
		while (left <= right && arr[right] > pivot)
			right--;
		if (left > right)
			break ;
		swap(&arr[left], &arr[right]);
	}
	swap(&arr[start], &arr[right]);
	quick_sort(arr, start, right);
	quick_sort(arr, right + 1, end);
}

int	*init_ordered_array(t_list_info *list_info)
{
	t_list	*cursor;
	int		*arr;
	int		i;

	cursor = list_info->head;
	arr = (int *)malloc(sizeof(int) * list_info->len);
	if (arr == NULL)
		exit(1);
	i = 0;
	while (cursor != NULL)
	{
		arr[i++] = cursor->data;
		cursor = cursor->next;
	}
	quick_sort(arr, 0, list_info->len);
	return (arr);
}

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
				cursor->rank = i + 1;
				break ;
			}
			cursor = cursor->next;
		}
		i++;
	}
}

void	init_tool(t_tool *tool, t_list_info *a, t_list_info *b, int *answer)
{
	tool->a_info = a;
	tool->b_info = b;
	tool->answer = answer;
}	
