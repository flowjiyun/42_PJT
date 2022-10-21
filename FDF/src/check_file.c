/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:49:03 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 13:13:15 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_valid_file(char *file_path)
{
	char	**arr_str;
	int		index;

	arr_str = ft_split(file_path, '.');
	if (!arr_str)
		terminate("error : malloc");
	index = -1;
	while (arr_str[++index])
		;
	if ((ft_strncmp(arr_str[index - 1], "fdf", 3) == 0)
		&& (ft_strlen("fdf") == ft_strlen(arr_str[index - 1])))
	{
		free_2d(arr_str);
		return (0);
	}
	else
	{
		free_2d(arr_str);
		return (1);
	}
}
