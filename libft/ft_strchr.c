/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:23:32 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/07 11:28:57 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (&s[len]);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == new_c)
			return (&s[i]);
		i++;
	}
	return (0);
}
