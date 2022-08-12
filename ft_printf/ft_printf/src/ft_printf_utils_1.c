/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:18:37 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/12 16:59:13 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	is_flag(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "-+ 0#";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_flag(const char **str)
{
	int		flag;

	flag = 0;
	while (is_flag(**str))
	{
		if (**str == '0')
			flag |= ZEROPAD;
		else if (**str == '+')
			flag |= PLUS;
		else if (**str == ' ')
			flag |= SPACE;
		else if (**str == '-')
			flag |= LEFT;
		else if (**str == '#')
			flag |= SPECIAL;
		++*str;
	}
	return (flag);
}

int	check_width(const char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = 10 * width + (**str - '0');
		++*str;
	}
	return (width);
}

int	check_precision(const char **str)
{
	int	precision;

	precision = -1;
	if (**str == '.')
	{
		++*str;
		precision = 0;
		while (ft_isdigit(**str))
		{
			precision = 10 * precision + (**str - '0');
			++*str;
		}
	}
	return (precision);
}

int	print(const char **str, t_option *option, long *len, va_list ap)
{
	int	ret;

	ret = 1;
	if (**str == 'c')
		ret = print_option_c(option, len, ap);
	else if (**str == 's')
		ret = print_option_s(option, len, ap);
	else if (**str == 'p')
		ret = print_option_p(option, len, ap);
	else if (**str == 'd' || **str == 'i')
		ret = print_option_d_i(option, len, ap);
	else if (**str == 'u')
		ret = print_option_u(option, len, ap);
	else if (**str == 'x')
	{
		option->flag |= SMALL;
		ret = print_option_x(option, len, ap);
	}
	else if (**str == 'X')
		ret = print_option_x(option, len, ap);
	else if (**str == '%')
	{
		option->flag |= PER;
		ret = print_option_per(option, len);
	}
	return (ret);
}
