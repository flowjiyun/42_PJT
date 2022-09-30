/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/30 18:38:08 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"
#include "../include/libft.h"
#include <stdio.h>

void	get_path_list(t_list_info *list_info, char **arr_path, char **arr_pwd)
{
	int	i;
	int	j;
	t_list	*node;

	i = -1;
	while (arr_path[++i])
	{
		node = make_node(arr_path[i]);
		push_back(list_info, node);
	}
	j = -1;
	while (arr_pwd[++j])
	{
		node = make_node(arr_pwd[j]);
		push_back(list_info, node);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	char		*path;
	char		*pwd;
	char		**arr_path;
	char		**arr_pwd;
	t_list_info	path_list;

	i = 0;
	(void)argc;
	(void)argv;
	while (envp[i])
	{	
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			path = envp[i];
		if (ft_strncmp("PWD", envp[i], 3) == 0)
			pwd = envp[i];
		i++;
	}
	path += 5;
	arr_path = ft_split(path, ':');
	pwd += 4;
	arr_pwd = ft_split(pwd, ':');
	get_path_list(&path_list, arr_path, arr_pwd);	
	for (int i = 0; arr_path[i]; i++)
		printf("%s\n", arr_path[i]);
	for (int i = 0; arr_pwd[i]; i++)
		printf("%s\n", arr_pwd[i]);
	printf("---------------------------\n");
	while (path_list.head)
	{
		printf("%s\n", (char *)path_list.head->content);
		path_list.head = path_list.head->next;
	}
	return (0);
}
