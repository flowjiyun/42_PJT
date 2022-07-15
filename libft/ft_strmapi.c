/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:30:53 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/15 09:47:09 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	size_t			s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (0);
	while (s[i] != 0)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
