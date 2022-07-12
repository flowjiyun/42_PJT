/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:11:19 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/07 13:40:51 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*new_s;

	new_s = (const unsigned char *)s;
	i = 0;
	if (s == 0)
		return (0);
	while (n--)
	{
		if (new_s[i] == (unsigned int)c)
		{
			return ((void *)&new_s[i]);
		}
		i++;
	}
	return (0);
}
