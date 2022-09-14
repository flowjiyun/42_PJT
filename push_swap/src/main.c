/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/14 13:56:12 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list_info	a_info;
	t_list_info	b_info;
	int			*answer;

	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	init_list_info(&a_info);
	init_list_info(&b_info);
	init_list(&a_info, argc, argv);
	answer = init_ordered_array(&a_info);
	parse_list(&a_info, answer);
	sort_a(&a_info, &b_info, 0);
	print_list(&a_info);
	print_list(&b_info);
	printf("a_len : %d\n", a_info.len);
	printf("b_len : %d\n", b_info.len);
	return (0);
}
