/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:17:51 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/19 14:30:50 by jiyunpar         ###   ########.fr       */
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

static int	check_valid_input(char **list)
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

int	init_list(t_list_info *list_info, int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*node;
	char	**list;

	i = 1;
	while (i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (check_valid_input(list) == 1)
		{
			j = 0;
			while (list[j] != 0)
			{
				node = make_node(ft_atoi(list[j++]));
				push_front(list_info, node);
			}
			i++;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
