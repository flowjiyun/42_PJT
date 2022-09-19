/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/19 14:29:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_info	a_info;
	t_list_info	b_info;
	// int			*answer;
	// t_tool		tool;

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	init_list_info(&a_info, &b_info);
	if (init_list(&a_info, argc, argv) == 0)
		write(1, "Error\n", 6);
	// answer = init_ordered_array(&a_info);
	// parse_list(&a_info, answer);
	// init_tool(&tool, &a_info, &b_info, answer);
	// push_swap(&tool);
	print_list(&a_info);
	// printf("\n");
	// for (int i = 0; i < a_info.len; i++)
	// 	printf("%d ", answer[i]);
	return (0);
}
