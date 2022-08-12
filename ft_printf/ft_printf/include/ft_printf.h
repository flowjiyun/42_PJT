/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:16:40 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/12 17:07:58 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

# define ZEROPAD 1 	// 0
# define SIGNED 2 	// specifier 구별! (d, i)
# define PLUS 4 	// + 
# define SPACE 8 	// 공백
# define LEFT 16 	// -
# define SMALL 32 	// 작은 x
# define SPECIAL 64 // #
# define PER 128 // %
# define ZERO 256 // precision == 0

typedef struct s_option
{
	int	flag;
	int	width;
	int	precision;
}	t_option;

int		ft_printf(const char *str, ...);
long	do_printf(const char *str, va_list ap);
int		print(const char **str, t_option *option, long *len, va_list ap);
int		check_precision(const char **str);
int		check_width(const char **str);
int		check_flag(const char **str);
int		is_flag(char c);
int		print_option_c(t_option *option, long *len, va_list ap);
int		print_option_s(t_option *option, long *len, va_list ap);
int		print_option_d_i(t_option *option, long *len, va_list ap);
int		print_option_u(t_option *option, long *len, va_list ap);
int		print_option_x(t_option *option, long *len, va_list ap);
int		print_option_p(t_option *option, long *len, va_list ap);
int		print_option_per(t_option *option, long *len);
void	ft_get_hex(unsigned long num, char *base, char hex[]);
int		ft_print_width(t_option *option, long *len);
void	ft_flag_toggle(t_option *option);
void	ft_calc_width_d(t_option *option, int num_len, int d_i);
int		write_sign(t_option *option, long *len);
int		ft_print_width_hex(t_option *option, long *len, char val);
char	ft_check_insert(t_option *option);
int		ft_putnbr(long n, long *len);
int		ft_putchar(char c);
int		ft_get_num_len(long num, int base);
int		ft_print_sharp(t_option *option, long *len, unsigned int x);
void	ft_calc_sharp_width(t_option *option, int hex_len, unsigned long x);

#endif