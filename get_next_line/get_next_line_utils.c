/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/18 18:06:42 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	i = -1;
	while (s1[++i] != 0)
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		ptr[i + j] = s2[j];
	ptr[i + j] = 0;
	free(s1);
	return (ptr);
}

int	is_nl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	unsigned int	i;

	if (!dest && !src)
		return (0);
	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		new_dest[i] = new_src[i];
		i++;
	}
	return (dest);
}
