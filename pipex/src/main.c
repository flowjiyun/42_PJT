/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/07 15:26:53 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	init_tool(t_tool *tool, int argc)
{
	init_list(&tool->cmd_list, 1);
	init_list(&tool->path_list, 0);
	tool->cmd_num = argc - 3;
}

static void	set_std_stream(t_tool *tool, int argc, char **argv, int index)
{
	if (dup2(tool->fdin, 0) == -1)
		print_error();
	if (close(tool->fdin) == -1)
		print_error();
	if (index == tool->cmd_num - 1)
	{
		tool->fdout = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (tool->fdout == -1)
			print_error();
	}
	else
	{
		if (pipe(tool->fds) == -1)
			print_error();
		tool->fdin = tool->fds[0];
		tool->fdout = tool->fds[1];
	}
	if (dup2(tool->fdout, 1) == -1)
		print_error();
	if (close(tool->fdout) == -1)
		print_error();
}

static int	make_child(t_tool *tool, t_list *cur_cmd)
{
	int		ret;
	char	*cmd;

	ret = fork();
	if (ret == -1)
		print_error();
	if (ret == 0)
	{
		cmd = check_valid_cmd(&tool->path_list, cur_cmd);
		if (!cmd)
			print_error();
		if (execve(cmd, cur_cmd->content, NULL) == -1)
			print_error();
	}
	return (ret);
}

static void	pipex(t_tool *tool, int argc, char **argv)
{
	int		i;
	int		ret;
	t_list	*cur_cmd;

	i = -1;
	tool->fdin = open(argv[1], O_RDONLY);
	if (tool->fdin == -1)
		print_error();
	cur_cmd = tool->cmd_list.head;
	while (++i < tool->cmd_num)
	{
		set_std_stream(tool, argc, argv, i);
		ret = make_child(tool, cur_cmd);
		cur_cmd = cur_cmd->next;
	}
	if (waitpid(ret, NULL, 0) == -1)
		print_error();
}

int	main(int argc, char **argv, char **envp)
{
	t_tool		tool;

	if (argc != 5)
	{
		write(1, "arg error\n", 10);
		exit(1);
	}
	init_tool(&tool, argc);
	get_path_list(&tool.path_list, envp);
	get_arg_list(&tool.cmd_list, argc, argv);
	pipex(&tool, argc, argv);
	clear_list(&tool.cmd_list);
	clear_list(&tool.path_list);
	return (0);
}
