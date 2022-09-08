/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/08 17:18:04 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list.h"

int	main(int argc, char **argv)
{
	t_list_info	a_info;
	t_list_info	b_info;

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_list_info(&a_info);
	init_list_info(&b_info);
	init_list(&a_info, argc, argv);
	ra(&a_info);
	// sa(&a_info);
	// pb(&a_info, &b_info);
	print_list(&a_info);
	print_list(&b_info);
	clear_list(&a_info);
	clear_list(&b_info);
	return (0);
}
