/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:17:51 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 14:43:52 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static int	check_long_max(const char *str, long value, int sign, int index)
{
	if ((value > 922337203685477580 || (value == 922337203685477580 \
	&& (str[index] - '0') > 7)) && sign == 1)
		return (-1);
	else if ((value > 922337203685477580 || (value == 922337203685477580 \
	&& (str[index] - '0') > 8)) && sign == -1)
		return (0);
	return (1);
}

static int	ft_atoi(const char *str)
{
	int		sign;	
	long	value;
	int		i;

	sign = 1;
	value = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_long_max(str, value, sign, i) == -1)
			return (-1);
		else if (check_long_max(str, value, sign, i) == 0)
			return (0);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(value * sign));
}

// int	check_valid_input(int argc, char **argv)
// {
// 	return (0);
// }

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
	return (arr);
}
