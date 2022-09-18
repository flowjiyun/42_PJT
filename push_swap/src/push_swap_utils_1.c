/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:17:51 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/18 17:38:26 by jiyunpar         ###   ########.fr       */
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

	i = 0;
	while (list[i] != 0)
	{	
		j = 0;
		while (list[i][j] != 0)
		{
			if (list[i][j] >= '0' && list[i][j] <= '9')
			{
				j++;
				continue ;
			}
			else
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
	return (1);
}

static char	**check_valid_input(int argc, char **argv)
{
	int		i;
	char	**list;

	i = 0;
	while (++i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (check_digit(list) == 1)
			continue ;
	}
	return (list);
}

void	init_list(t_list_info *list_info, int argc, char **argv)
{
	int		i;
	t_list	*node;
	char	**list;

	i = 0;
	list = check_valid_input(argc, argv);
	if (list > 0)
	{
		while (list[i] != 0)
		{
			node = make_node(ft_atoi(list[i]));
			push_front(list_info, node);
			i++;
		}
	}
}
