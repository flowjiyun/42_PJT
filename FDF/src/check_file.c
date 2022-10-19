/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:49:03 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/19 22:42:04 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(arr_str);
		return (0);
	}
	else
	{
		free(arr_str);
		return (1);
	}
}
