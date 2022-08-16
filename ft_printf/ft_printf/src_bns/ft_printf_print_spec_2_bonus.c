/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_spec_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:11:38 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/16 10:51:57 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	print_option_d_i(t_option *option, long *len, va_list ap)
{
	int	d_i;
	int	d_i_len;

	d_i = va_arg(ap, int);
	d_i_len = get_num_len(d_i, 10);
	if (d_i < 0)
		option->flag |= SIGNED;
	if (option->precision == 0 && d_i == 0)
		option->flag |= ZERO;
	calc_width_d(option, d_i_len, d_i);
	if (write_d_i(option, len, d_i) == -1)
		return (-1);
	return (1);
}

int	print_option_u(t_option *option, long *len, va_list ap)
{
	unsigned int	u;
	int				u_len;

	u = va_arg(ap, unsigned int);
	u_len = get_num_len(u, 10);
	if (option->precision == 0 && u == 0)
		option->flag |= ZERO;
	calc_width_d(option, u_len, u);
	if (write_u(option, len, u) == -1)
		return (-1);
	return (1);
}

int	write_d_i(t_option *option, long *len, int d_i)
{
	if (!(option->flag & LEFT))
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	if (print_sign(option, len) == -1)
		return (-1);
	if (print_width(option, len, '0') == -1)
		return (-1);
	if (!(option->flag & ZERO))
	{
		if (ft_putnbr(d_i, len) == -1)
			return (-1);
	}
	if (option->flag & LEFT)
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	return (1);
}

int	write_u(t_option *option, long *len, unsigned int u)
{
	if (!(option->flag & LEFT))
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	if (print_sign(option, len) == -1)
		return (-1);
	if (print_width(option, len, '0') == -1)
		return (-1);
	if (!(option->flag & ZERO))
	{
		if (ft_putnbr(u, len) == -1)
			return (-1);
	}
	if (option->flag & LEFT)
	{
		if (print_width(option, len, ' ') == -1)
			return (-1);
	}
	return (1);
}
