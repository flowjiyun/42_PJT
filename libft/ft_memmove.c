/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:20:40 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/08 20:10:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

int main(void)
{
	char a[] = "123456789000000";
	printf("%s", memmove(a + 3, a, 3));
	printf("\n");
	printf("%s", ft_memmove(a + 3, a, 3));
	return (0);
}