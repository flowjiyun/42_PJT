/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calc_width_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:14:00 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/16 10:51:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	calc_width_d(t_option *option, int num_len, int d_i)
{
	int	spec;

	spec = 0;
	if (option->flag & SIGNED || option->flag & PLUS \
	|| option->flag & SPACE)
		spec = 1;
	if (option->flag & ZERO && d_i == 0)
		num_len--;
	if (option->width > option->precision)
		calc_width_gt(option, num_len, spec);
	else if (option->precision >= option->width)
		calc_precision_gt(option, num_len);
}

void	calc_width_hex(t_option *option, int hex_len, unsigned int x)
{
	int	spec;

	spec = 0;
	if (option->flag & SPECIAL && x != 0)
		spec = 2;
	if (option->flag & ZERO && x == 0)
		hex_len--;
	if (option->width > option->precision)
		calc_width_gt(option, hex_len, spec);
	else if (option->precision >= option->width)
		calc_precision_gt(option, hex_len);
}

void	calc_width_gt(t_option *option, int strlen, int spec)
{
	if (strlen < option->precision)
	{
		option->precision -= strlen;
		option->width -= option->precision + strlen + spec;
	}
	else if ((option->flag & ZEROPAD) && option->precision == -1)
	{
		option->precision = option->width - strlen - spec;
		option->width = 0;
	}
	else
	{
		option->width -= strlen + spec;
		option->precision = 0;
	}
}

void	calc_precision_gt(t_option *option, int strlen)
{
	if (strlen < option->precision)
	{
		option->precision -= strlen;
		option->width = 0;
	}
	else
	{
		option->precision = 0;
		option->width = 0;
	}
}
