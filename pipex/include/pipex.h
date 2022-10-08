/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:12:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/08 17:00:37 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "linked_list.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_tool
{
	t_list_info	path_list;
	t_list_info	cmd_list;
	int			fds[2];
	int			fdin;
	int			fdout;
	int			cmd_num;
}	t_tool;

void	get_path_list(t_list_info *list_info, char **envp);
void	get_arg_list(t_list_info *list_info, int argc, char **argv);
char	*check_valid_cmd(t_list_info *path, t_list *cur_cmd);
void	print_error(char *str);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif