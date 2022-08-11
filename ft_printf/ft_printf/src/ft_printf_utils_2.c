/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:18:06 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/11 18:47:27 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_width(t_option *option, long *len)
{
	char	val;

	val = ft_check_insert(option);
	while ((option->width)-- > 0)
	{
		write(1, &val, 1);
		(*len)++;
	}
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

void	ft_print_digit(long num, int num_len, long *len)
{
	long	nbr;
	int		div;
	char	digit;

	nbr = num;
	div = 1;
	while (--num_len)
		div *= 10;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	while (div > 0)
	{
		digit = nbr / div + '0';
		write(1, &digit, 1);
		nbr %= div;
		div /= 10;
		(*len)++;
	}
}
