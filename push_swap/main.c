/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:25 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/25 14:01:49 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check each argv with isdigit to figure out if input is integer
int	is_valid_input(int argc, char **argv)
{
	int	i;

	if (argc == 0)
		return (1);
	i = 1;
}

int	main(int argc, char **argv)
{
	if (is_valid_input(argc, argv))
		write(2, "Error\n", 6);
	return (0);
}

int	call(int a)
{
	return (0);
}
