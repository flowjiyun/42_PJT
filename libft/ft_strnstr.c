/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/08 18:08:24 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}

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
