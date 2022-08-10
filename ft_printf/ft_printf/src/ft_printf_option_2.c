/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_option_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:18:17 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/10 22:12:55 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_flag_toggle(t_option *option)
{
	if (option->precision > option->width)
	{
		if (option->flag & LEFT)
			option->flag &= ~LEFT;
		option->flag |= ZEROPAD;
	}
	else if (option->flag & ZEROPAD && option->width > option->precision \
	&& option->precision != -1)
		option->flag &= ~ZEROPAD;
	if (option->flag & SIGNED)
	{
		option->flag &= ~PLUS;
		option->flag &= ~SPACE;
	}
}

void	write_sign(t_option *option, long *len)
{
	if (option->flag & SIGNED)
	{
		write(1, "-", 1);
		(*len)++;
	}
	else if (option->flag & PLUS)
	{
		write(1, "+", 1);
		(*len)++;
	}
	else if (option->flag & SPACE)
	{
		write(1, " ", 1);
		(*len)++;
	}
}

void	ft_calc_width_d(t_option *option, int num_len)
{
	int spec;

	spec = 0;
	if (option->flag & SIGNED || option->flag & PLUS \
	|| option->flag & SPACE)
		spec = 1;
	if (option->width > option->precision)
	{
		if (num_len < option->precision)
		{
			option->precision -= num_len;
			option->width -= option->precision + num_len + spec;
		}
		else if ((option->flag & ZEROPAD) && option->precision == -1)
		{
			option->precision = option->width - num_len - spec;
			option->width = 0;
		}
		else
		{
			option->width -= num_len + spec;
			option->precision = 0;
		}
	}
	else if (option->precision >= option->width)
	{
		if (num_len < option->precision)
		{
			option->precision -= num_len;
			option->width = 0;
		}
		else
		{
			option->precision = 0;
			option->width = 0;
		}
	}
}

void	ft_calc_sharp_width(t_option *option, int hex_len, unsigned int x)
{
	int	spec;

	spec = 0;
	if (option->flag & SPECIAL && x != 0)
		spec = 2;
	if (option->width > option->precision)
	{
		if (hex_len < option->precision)
		{
			option->precision -= hex_len;
			option->width -= option->precision + hex_len + spec;
		}
		else if ((option->flag & ZEROPAD) && option->precision == -1)
		{
			option->precision = option->width - hex_len;
			option->width = 0;
		}
		else
		{
			option->width -= hex_len + spec;
			option->precision = 0;
		}
	}
	else if (option->precision >= option->width)
	{
		if (hex_len < option->precision)
		{
			option->precision -= hex_len;
			option->width = 0;
		}
		else
		{
			option->precision = 0;
			option->width = 0;
		}
	}
}

void	ft_print_width_hex(t_option *option, long *len, char val)
{
	if (val == ' ')
	{
		while (option->width-- > 0)
		{
			(*len)++;
			write(1, &val, 1);
		}
	}
	else if (val == '0')
	{
		while (option->precision-- > 0)
		{
			(*len)++;
			write(1, &val, 1);
		}
	}
}

void	ft_print_sharp(t_option *option, long *len, unsigned int x)
{
	if (x != 0)
	{
		if (option->flag & SMALL)
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		(*len) = (*len) + 2;
	}
}

void	print_option_d_i(t_option *option, long *len, va_list ap)
{
	int	d_i;
	int	d_i_len;

	d_i = va_arg(ap, int);
	d_i_len = ft_get_num_len(d_i, 10);
	if (d_i < 0)
		option->flag |= SIGNED;
	ft_flag_toggle(option);
	ft_calc_width_d(option, d_i_len);
	if (!(option->flag & LEFT))
	{
		ft_print_width_hex(option, len, ' ');
		write_sign(option, len);
		ft_print_width_hex(option, len, '0');
		ft_print_digit(d_i, d_i_len, len);
	}
	else
	{
		write_sign(option, len);
		ft_print_width_hex(option, len, '0');
		ft_print_digit(d_i, d_i_len, len);
		ft_print_width_hex(option, len, ' ');
	}
}

void	print_option_u(t_option *option, long *len, va_list ap)
{
	unsigned int	u;
	int				u_len;

	u = va_arg(ap, unsigned int);
	u_len = ft_get_num_len(u, 10);
	ft_flag_toggle(option);
	ft_calc_width_d(option, u_len);
	if (!(option->flag & LEFT))
	{
		ft_print_width_hex(option, len, ' ');
		write_sign(option, len);
		ft_print_width_hex(option, len, '0');
		ft_print_digit(u, u_len, len);
	}
	else
	{
		write_sign(option, len);
		ft_print_width_hex(option, len, '0');
		ft_print_digit(u, u_len, len);
		ft_print_width_hex(option, len, ' ');
	}
}

void	print_option_x(t_option *option, long *len, va_list ap)
{
	unsigned int	x;
	char			hex[18];
	int				hex_len;

	x = va_arg(ap, unsigned int);
	if (option->flag & SMALL)
		ft_get_hex((unsigned long)x, "0123456789abcdef", hex);
	else
		ft_get_hex((unsigned long)x, "0123456789ABCDEF", hex);
	hex_len = ft_strlen(hex);
	//ft_flag_toggle(option);
	ft_calc_sharp_width(option, hex_len, x);
	if (option->flag & SPECIAL)
	{
		if (!(option->flag & LEFT))
		{
			ft_print_width_hex(option, len, ' ');
			ft_print_sharp(option, len, x);
			ft_print_width_hex(option, len, '0');
			write(1, hex, hex_len);
			(*len) = (*len) + hex_len;
		}
		else
		{
			ft_print_sharp(option, len, x);
			ft_print_width_hex(option, len, '0');
			write(1, hex, hex_len);
			ft_print_width_hex(option, len, ' ');
			(*len) = (*len) + hex_len;
		}
	}
	else
	{
		if (!(option->flag & LEFT))
		{
			ft_print_width_hex(option, len, ' ');
			ft_print_width_hex(option, len, '0');
			write(1, hex, hex_len);
			(*len) = (*len) + hex_len;
		}
		else
		{
			ft_print_width_hex(option, len, '0');
			write(1, hex, hex_len);
			ft_print_width_hex(option, len, ' ');
			(*len) = (*len) + hex_len;
		}
	}
}

void	print_option_p(t_option *option, long *len, va_list ap)
{
	void			*x;
	char			hex[18];
	int				hex_len;

	x = va_arg(ap, void *);
	ft_get_hex((unsigned long)x, "0123456789abcdef", hex);
	hex_len = ft_strlen(hex);
	ft_flag_toggle(option);
	ft_calc_width_d(option, hex_len);
	option->width -= 2;
	if (!(option->flag & LEFT))
	{
		ft_print_width_hex(option, len, ' ');
		write(1, "0x", 2);
		write(1, hex, hex_len);
		*len += hex_len;
	}
	else
	{
		write(1, "0x", 2);
		write(1, hex, hex_len);
		ft_print_width_hex(option, len, ' ');
		*len += hex_len;
	}
	*len += 2;
}
