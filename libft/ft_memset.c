/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:54:30 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/13 10:16:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*new_ptr;

	new_ptr = (unsigned char *)ptr;
	if (ptr != 0)
	{
		while (len--)
		{
			*new_ptr = (unsigned char)value;
			new_ptr++;
		}
	}
	return (ptr);
}
