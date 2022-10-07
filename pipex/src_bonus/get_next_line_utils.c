/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/07 16:50:14 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

unsigned int	ft_strlen_1(const char *str)
{
	unsigned int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen_1(str) + 1));
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin_1(char *s1, char *s2)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;

	temp = (char *)malloc(sizeof(char) * (ft_strlen_1(s1) + ft_strlen_1(s2) + 1));
	if (!temp)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		temp[i] = s1[i];
	j = -1;
	while (s2[++j])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

int	is_newline(const char *backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (-1);
	while (backup[i] != '\0')
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_memcopy(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	unsigned int	i;

	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	i = -1;
	while (++i < size)
		new_dest[i] = new_src[i];
}
