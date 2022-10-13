/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/13 18:49:39 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define FD_MAX 256
# define BUFFER_SIZE 1024

char			*get_next_line(int fd);

int				is_newline(const char *backup);
unsigned int	ft_strlen_1(const char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin_1(char *s1, char *s2);
void			ft_memcopy(void *dest, const void *src, size_t size);

#endif