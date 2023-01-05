/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:20:50 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 18:37:25 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static bool	is_input_has_alpha(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+')
		++i;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (true);
		++i;
	}
	return (false);
}

bool	is_valid_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_input_has_alpha(argv[i]) == true)
			return (false);
		++i;
	}
	return (true);
}
