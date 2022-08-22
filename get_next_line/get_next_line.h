/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/22 15:26:50 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define FD_MAX 256

char			*get_next_line(int fd);
char			*update_backup(char **backup);
char			*get_line(char **backup);
char			*read_file(int fd, char **backup, char *buf);

int				is_newline(const char *backup);
unsigned int	ft_strlen(const char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			ft_memcopy(void *dest, const void *src, size_t size);

#endif