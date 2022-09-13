/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/13 14:46:10 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list.h"

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
	for (int i = 0; i < a_info.len; i++)
		printf("%d ", answer[i]);
	return (0);
}
