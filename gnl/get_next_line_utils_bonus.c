/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/03 23:53:43 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		s1[0] = '\0';
	}
	i = -1;
	while (s1[++i] != 0)
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		ptr[i + j] = s2[j];
	ptr[i + j] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	new_c;

	i = 0;
	len = 0;
	new_c = (char)c;
	while (s[i] != 0)
	{
		len++;
		i++;
	}
	if (new_c == 0)
		return ((char *)&s[len]);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == new_c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
