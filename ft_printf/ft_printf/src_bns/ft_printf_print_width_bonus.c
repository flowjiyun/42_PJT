/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_width_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:04:14 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/16 10:53:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	print_width_c(t_option *option, long *len)
{
	char	val;

	val = check_insert(option);
	while ((option->width)-- > 0)
	{
		if (write(1, &val, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (1);
}

char	check_insert(t_option *option)
{
	char	val;

	if (option->flag & ZEROPAD)
	{
		if (option->flag & PER)
			val = ' ';
		else
			val = '0';
	}
	else
		val = ' ';
	return (val);
}

int	print_sign(t_option *option, long *len)
{
	if (option->flag & SIGNED)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*len)++;
	}
	else if (option->flag & PLUS)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
		(*len)++;
	}
	else if (option->flag & SPACE)
	{
		if (write(1, " ", 1) == -1)
			return (-1);
		(*len)++;
	}
	return (1);
}

int	print_width(t_option *option, long *len, char val)
{
	if (val == ' ')
	{
		while (option->width-- > 0)
		{
			if (write(1, &val, 1) == -1)
				return (-1);
			(*len)++;
		}
	}
	else if (val == '0')
	{
		while (option->precision-- > 0)
		{
			if (write(1, &val, 1) == -1)
				return (-1);
			(*len)++;
		}
	}
	return (1);
}

int	print_sharp(t_option *option, long *len, unsigned char x)
{
	if (option->flag & SPECIAL)
	{
		if (x != '0')
		{
			if (option->flag & SMALL)
			{
				if (write(1, "0x", 2) == -1)
					return (-1);
			}
			else
			{
				if (write(1, "0X", 2) == -1)
					return (-1);
			}
			(*len) = (*len) + 2;
		}
	}
	return (1);
}
