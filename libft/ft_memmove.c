/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:20:40 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/13 10:16:10 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	else if (dst < src)
	{
		while (len--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst += len - 1;
		new_src += len - 1;
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
