/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:16:40 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/16 10:49:14 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

# define ZEROPAD 1
# define SIGNED 2
# define PLUS 4
# define SPACE 8
# define LEFT 16
# define SMALL 32
# define SPECIAL 64
# define PER 128
# define ZERO 256

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

int		ft_putnbr(long n, long *len);
int		ft_putchar(char c);
int		get_num_len(long num, int base);
void	get_hex(unsigned long num, char *base, char hex[]);

int		print_option_c(t_option *option, long *len, va_list ap);
int		print_option_s(t_option *option, long *len, va_list ap);
int		print_option_per(t_option *option, long *len);

int		print_option_d_i(t_option *option, long *len, va_list ap);
int		print_option_u(t_option *option, long *len, va_list ap);
int		write_d_i(t_option *option, long *len, int d_i);
int		write_u(t_option *option, long *len, unsigned int u);

int		print_option_x(t_option *option, long *len, va_list ap);
int		print_option_p(t_option *option, long *len, va_list ap);
int		write_x(t_option *option, long *len, char hex[], int hex_len);
int		write_p(t_option *option, long *len, char hex[], int hex_len);

int		print_width_c(t_option *option, long *len);
char	check_insert(t_option *option);
int		print_sign(t_option *option, long *len);
int		print_width(t_option *option, long *len, char val);
int		print_sharp(t_option *option, long *len, unsigned char x);

void	calc_width_hex(t_option *option, int hex_len, unsigned int x);
void	calc_width_d(t_option *option, int num_len, int d_i);
void	calc_width_gt(t_option *option, int strlen, int spec);
void	calc_precision_gt(t_option *option, int strlen);

#endif