/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:02:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/21 13:47:00 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_2d(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	if (!str)
		return (0);
	while (str[++len])
		;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*get_next_line_short(int fd)
{
	char	*str;
	char	*temp;

	str = (char *)malloc(sizeof(char) * 10000);
	if (!str)
		terminate("ERROR : MALLOC");
	temp = str;
	while (read(fd, temp, 1) > 0 && *temp++ != '\n')
		;
	if (temp > str)
	{
		*temp = 0;
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}
