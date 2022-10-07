/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:59:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/07 17:27:56 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_arg_list(t_list_info *list_info, int argc, char **argv)
{
	int		i;
	char	**arr_str;
	t_list	*node;

	i = 1;
	while (++i < argc - 1)
	{
		arr_str = ft_split(argv[i], ' ');
		node = make_node(arr_str);
		push_back(list_info, node);
	}
}