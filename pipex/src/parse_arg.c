/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:59:39 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/04 13:26:06 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	get_arg_list(t_list_info *list_info, char **argv)
{
	int		i;
	char	**arr_str;
	t_list	*node;

	i = 0;
	while (argv[++i])
	{
		arr_str = ft_split(argv[i], ' ');
		node = make_node(arr_str);
		push_back(list_info, node);
	}
}