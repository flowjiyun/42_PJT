/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:18:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/12 17:01:18 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_width(t_option *option, long *len)
{
	char	val;

	val = ft_check_insert(option);
	while ((option->width)-- > 0)
	{
		if (write(1, &val, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (1);
}

char	ft_check_insert(t_option *option)
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

int	ft_get_num_len(long num, int base)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = num;
	if (nbr < 0)
		nbr *= -1;
	else if (nbr == 0)
	{
		len++;
		return (len);
	}
	while (nbr >= base)
	{
		nbr /= base;
		len++;
	}
	return (++len);
}

void	ft_get_hex(unsigned long num, char *base, char res[])
{
	char	hexa[16];
	int		i;
	int		j;

	i = 0;
	if (num == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return ;
	}
	while (num > 0)
	{
		hexa[i++] = base[num % 16];
		num /= 16;
	}
	j = 0;
	while (i > 0)
		res[j++] = hexa[--i];
	res[j] = '\0';
}

int	ft_putnbr(long num, long *len)
{
	if (num < 0)
		num *= -1;
	if (num > 9)
	{
		if (ft_putnbr(num / 10, len) == -1)
			return (-1);
		num = num % 10;
	}
	if (ft_putchar(num + '0') == -1)
		return (-1);
	(*len)++;
	return (1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}