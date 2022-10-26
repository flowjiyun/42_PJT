/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:26:23 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/26 08:58:49 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	terminate(char *str)
{
	if (errno == 0)
	{
		write(2, str, ft_strlen(str));
	}
	else
		perror(str);
	exit(1);
}
