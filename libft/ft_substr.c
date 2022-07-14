/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:19:09 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/14 09:45:17 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_len;
	char			*ptr;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (0);
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
