/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/11 16:30:20 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**split_env(char **envp, char *str, size_t byte)
{
	int		i;
	char	*val;
	char	**arr_val;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(str, envp[i], byte) == 0)
			val = envp[i];
		i++;
	}
	val += (byte + 1);
	arr_val = ft_split(val, ':');
	return (arr_val);
}

static void	init_path_list(t_list_info *list, char **arr_path, char **arr_pwd)
{
	int		i;
	int		j;
	char	*root;
	t_list	*node;

	root = (char *)malloc(2);
	if (!root)
		print_error("malloc");
	root[0] = '/';
	root[1] = 0;
	i = -1;
	while (arr_path[++i])
	{
		node = make_node(arr_path[i]);
		push_back(list, node);
	}
	j = -1;
	while (arr_pwd[++j])
	{
		node = make_node(arr_pwd[j]);
		push_back(list, node);
	}
	node = make_node(root);
	push_back(list, node);
}

void	get_path_list(t_list_info *list_info, char **envp)
{
	char		**arr_path;
	char		**arr_pwd;

	arr_path = split_env(envp, "PATH", 4);
	arr_pwd = split_env(envp, "PWD", 3);
	init_path_list(list_info, arr_path, arr_pwd);
	free(arr_path);
	free(arr_pwd);
}
