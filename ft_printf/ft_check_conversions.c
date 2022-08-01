/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:52:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/07/31 09:42:45 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	is_flag(char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '0')
		return (1);
	return (0);
}

int	is_width(char c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}

int	is_precision(char c)
{
	if (c == '.' || ft_isdigit(c))
		return (1);
	return (0);
}

int is_specifier(char c)
{
	if (c == 'c' || )
}

int	check_conversions(char c)
{
}