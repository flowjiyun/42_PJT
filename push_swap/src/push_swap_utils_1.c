/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:17:51 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 16:39:33 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../libft/libft.h"

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

void	init_list_info(t_list_info *list_info)
{
	list_info->head = NULL;
	list_info->tail = NULL;
	list_info->len = 0;
}

void	init_list(t_list_info *list_info, int argc, char **argv)
{
	int		i;
	t_list	*node;

	i = 0;
	while (++i < argc)
	{
		node = make_node(ft_atoi(argv[i]));
		push_front(list_info, node);
	}
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
