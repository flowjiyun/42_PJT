/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/21 16:14:07 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*update_backup(char *backup);
char			*get_line(char *backup);
char			*read_file(int fd, char *backup, char *buf);

int				is_newline(const char *backup);
unsigned int	ft_strlen(const char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			ft_memcopy(void *dest, const void *src, size_t size);

#endif