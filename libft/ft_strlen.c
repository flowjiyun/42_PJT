/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:04:50 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/13 10:16:54 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}
