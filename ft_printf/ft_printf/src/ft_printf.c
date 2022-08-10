/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:17:54 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/10 17:52:11 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	do_printf(const char *str, va_list ap)
{
	long		len;
	t_option	option;

	len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str++, 1);
			len++;
			continue ;
		}
		if (*(++str) != '\0')
		{
			option.flag = check_flag(&str);
			option.width = check_width(&str);
			option.precision = check_precision(&str);
			print(&str, &option, &len, ap);
			str++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, str);
	len = do_printf(str, ap);
	va_end(ap);
	return (len);
}
