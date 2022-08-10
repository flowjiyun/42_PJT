/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:18:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/10 20:54:02 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_option_c(t_option *option, long *len, va_list ap)
{
	unsigned char	c;

	c = va_arg(ap, int);
	option->width -= 1;
	if (!(option->flag & LEFT))
		ft_print_width(option, len);
	*len += write(1, &c, 1);
	ft_print_width(option, len);
}

void	print_option_s(t_option *option, long *len, va_list ap)
{
	char	*s;
	int		s_len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (option->precision != -1 && option->precision < s_len)
		s_len = option->precision;
	option->width -= s_len;
	if (!(option->flag & LEFT))
		ft_print_width(option, len);
	*len += write(1, s, s_len);
	ft_print_width(option, len);
}

void	print_option_per(t_option *option, long *len)
{
	option->width -= 1;
	if (!(option->flag & LEFT))
		ft_print_width(option, len);
	*len += write(1, "%", 1);
	ft_print_width(option, len);
}
