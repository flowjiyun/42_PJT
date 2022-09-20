/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:17:51 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/20 14:10:34 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../libft/libft.h"

void	init_list_info(t_list_info *a_info, t_list_info *b_info)
{
	a_info->head = NULL;
	a_info->tail = NULL;
	a_info->len = 0;
	b_info->head = NULL;
	b_info->tail = NULL;
	b_info->len = 0;
}

static int	check_digit(char **list)
{
	int	i;
	int	j;

	i = -1;
	while (list[++i] != 0)
	{	
		j = 0;
		if (list[i][j] == '-' || list[i][j] == '+')
		{
			j++;
			if (list[i][j] == 0)
				return (0);
		}
		while (list[i][j] != 0)
		{
			if (list[i][j] >= '0' && list[i][j] <= '9')
			{
				j++;
				continue ;
			}
			else
				return (0);
		}
	}
	return (1);
}

static int	check_valid_input(t_list_info *list_info, char **list)
{
	int		i;
	long	node_data;
	t_list	*node;

	if (check_digit(list) == 1)
	{
		i = 0;
		if (list[0] == 0)
			return (0);
		while (list[i] != 0)
		{
			node_data = ft_atoi(list[i++]);
			if (node_data > 2147483647 || node_data < -2147483648)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			node = make_node(node_data);
			push_front(list_info, node);
		}
		return (1);
	}
	else
		return (0);
}

static void	do_free(char **list)
{
	int	i;

	i = 0;
	while (list[i] != 0)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	init_list(t_list_info *list_info, int argc, char **argv)
{
	int		i;
	char	**list;

	i = 0;
	while (++i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (check_valid_input(list_info, list) == 1)
		{
			do_free(list);
			continue ;
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}
