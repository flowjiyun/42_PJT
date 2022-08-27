/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/27 17:39:35 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_list_info	a_info;

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_list(&a_info, argc, argv);
	swap_node_left(a_info.head->next->next, &a_info);
	print_list(&a_info);
	clear_list(&a_info);
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm -rf leaks_result_temp");
	return (0);
}
