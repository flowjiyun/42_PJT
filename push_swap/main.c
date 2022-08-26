/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/26 17:26:35 by jiyunpar         ###   ########.fr       */
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
	print_list(&a_info);
	clear_list(&a_info);
	//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm -rf leaks_result_temp");
	return (0);
}
