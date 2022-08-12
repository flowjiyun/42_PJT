/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:17:54 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/12 16:56:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long	do_printf(const char *str, va_list ap)
{
	long		len;
	t_option	option;

	len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			if (write(1, str++, 1) == -1)
				return (-1);
			len++;
			continue ;
		}
		if (*(++str) != '\0')
		{
			option.flag = check_flag(&str);
			option.width = check_width(&str);
			option.precision = check_precision(&str);
			if (print(&str, &option, &len, ap) == -1)
				return (-1);
			str++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	long	len;
	va_list	ap;

	va_start(ap, str);
	len = do_printf(str, ap);
	va_end(ap);
	if (len > INT_MAX)
		return (-1);
	return ((int)len);
}
