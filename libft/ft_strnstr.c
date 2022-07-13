/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/13 10:52:22 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	size_t				needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (len == 0 || len < needle_len)
		return (0);
	while (i <= len - needle_len && haystack[i] != 0)
	{
		j = 0;
		while (needle[j] != 0)
		{
			if (haystack[i + j] == needle[j])
			{
				j++;
				if (j == needle_len)
					return ((char *)&haystack[i]);
			}
			else
				break ;
		}		
	}
	return (0);
}
