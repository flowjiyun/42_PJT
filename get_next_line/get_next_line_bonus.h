/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:21 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/08/17 19:17:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# define ERROR -1
//# define BUFFER_SIZE 42

typedef struct s_file
{
	char			*backup;
	int				fd;
	struct s_file	*next;
}	t_file;

typedef struct s_list
{
	t_file	*head;
	int		len;
}	t_list;

char	*get_next_line(int fd);
t_file	*check_list(t_list *list, int fd);
void	delete_list(t_list *list, t_file *cur_file);
char	*read_file(t_file *cur_file, int fd);
char	*make_line(char *backup);
char	*update_backup(char *backup);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif