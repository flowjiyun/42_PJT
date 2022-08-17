/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/17 19:19:06 by jiyunpar         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_len;
	char			*ptr;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len >= s_len)
		len = s_len;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < len && s[start + i] != 0)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
