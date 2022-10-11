/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:12:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/11 15:31:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "linked_list.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_tool
{
	t_list_info	path_list;
	t_list_info	cmd_list;
	int			fds[2];
	int			curr_pipe_in;
	int			curr_pipe_out;
	int			prev_pipe_in;
	int			cmd_num;
	int			heredoc;
}	t_tool;

void			get_path_list(t_list_info *list_info, char **envp);
void			get_arg_list(t_list_info *list_info, int argc, char **argv);
char			*check_valid_cmd(t_list_info *path, t_list *cur_cmd);
void			print_error(char *str);
void			make_heredoc(int argc, char **argv);
int				check_heredoc(char **argv);
void			make_heredoc(int argc, char **argv);

char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);

#endif