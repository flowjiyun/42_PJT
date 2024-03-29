/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:12:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/12 11:11:15 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "linked_list.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_tool
{
	t_list_info	path_list;
	t_list_info	cmd_list;
	int			fds[2];
	int			curr_pipe_in;
	int			curr_pipe_out;
	int			prev_pipe_in;
	int			cmd_num;
}	t_tool;

void	get_path_list(t_list_info *list_info, char **envp);
void	get_arg_list(t_list_info *list_info, int argc, char **argv);
char	*check_valid_cmd(t_list_info *path, t_list *cur_cmd);
void	print_error(char *str);
void	pipex(t_tool *tool, int argc, char **argv);
void	init_tool(t_tool *tool, int argc);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif