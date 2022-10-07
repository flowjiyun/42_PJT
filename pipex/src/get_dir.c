/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:30:42 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/07 15:26:33 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_dir(t_list *cur_path, t_list *cur_cmd)
{
	char	*dir_slash;
	char	*dir;

	dir_slash = ft_strjoin((char *)cur_path->content, "/");
	dir = ft_strjoin(dir_slash, ((char **)cur_cmd->content)[0]);
	free(dir_slash);
	return (dir);
}

static int	is_accessible(char *dir)
{
	if (access(dir, X_OK | F_OK) == 0)
		return (1);
	else
		return (0);
}

char	*check_valid_cmd(t_list_info *path, t_list *cur_cmd)
{
	char	*cmd;
	t_list	*cur_path;

	cur_path = path->head;
	while (cur_path)
	{
		cmd = get_dir(cur_path, cur_cmd);
		if (is_accessible(cmd))
			return (cmd);
		else
		{
			cur_path = cur_path->next;
		}
	}
	return (NULL);
}
