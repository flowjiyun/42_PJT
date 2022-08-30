/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/30 18:23:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_info	a_info;
	t_list_info b_info;

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	check_valid_input(argc, argv);
	init_list(&a_info, argc, argv);
	swap_node_left(a_info.head->next->next, &a_info);
	print_list(&a_info);
	clear_list(&a_info);
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm -rf leaks_result_temp");
	return (0);
}
