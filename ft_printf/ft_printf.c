/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:47:47 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/29 18:42:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(const char *str, va_list ap)
{
	unsigned char	bit_status;

	bit_status = 0;
	while (*str != 0)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str,1);
			str++;
			continue;
		}
		++str;
		// flag들 비트마스킹 
		
		bit_status = get_status_init(&str, bit_status);
	}
	
}

unsigned char	get_status_init(const char **str, unsigned char bit_status)
{

}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	ft_vsprintf()

}