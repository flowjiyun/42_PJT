/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_spec_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:18:17 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/12 19:59:03 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_option_x(t_option *option, long *len, va_list ap)
{
	unsigned int	x;
	char			hex[18];
	int				hex_len;

	x = va_arg(ap, unsigned int);
	if (option->precision == 0 && x == 0)
		option->flag |= ZERO;
	if (option->flag & SMALL)
		get_hex((unsigned long)x, "0123456789abcdef", hex);
	else
		get_hex((unsigned long)x, "0123456789ABCDEF", hex);
	hex_len = ft_strlen(hex);
	calc_width_hex(option, hex_len, x);
	if (write_x(option, len, hex, hex_len) == -1)
		return (-1);
	return (1);
}

int	print_option_p(t_option *option, long *len, va_list ap)
{
	void			*x;
	char			hex[18];
	int				hex_len;

	x = va_arg(ap, void *);
	get_hex((unsigned long)x, "0123456789abcdef", hex);
	hex_len = ft_strlen(hex);
	calc_width_hex(option, hex_len, (unsigned int)x);
	option->width -= 2;
	if (write_p(option, len, hex, hex_len) == -1)
		return (-1);
	return (1);
}

int	write_x(t_option *option, long *len, char hex[], int hex_len)
{
	if (!(option->flag & LEFT))
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	if (print_sharp(option, len, hex[0]) == -1)
		return (-1);
	if (print_width(option, len, '0') == -1)
		return (-1);
	if (!(option->flag & ZERO))
	{
		if (write(1, hex, hex_len) == -1)
			return (-1);
		(*len) = (*len) + hex_len;
	}
	if (option->flag * LEFT)
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	return (1);
}

int	write_p(t_option *option, long *len, char hex[], int hex_len)
{
	if (!(option->flag & LEFT))
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	*len += 2;
	if (write(1, hex, hex_len) == -1)
		return (-1);
	*len += hex_len;
	if (option->flag & LEFT)
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	return (1);
}
