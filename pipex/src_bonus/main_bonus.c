/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/11 16:29:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_tool(t_tool *tool, int argc)
{
	init_list(&tool->cmd_list, 1);
	init_list(&tool->path_list, 0);
	tool->cmd_num = argc - 3;
	tool->prev_pipe_in = -1;
	tool->heredoc = 0;
}

static void	set_pipe(t_tool *tool, int argc, char **argv, int i)
{
	if (i == tool->cmd_num - 1)
	{
		tool->curr_pipe_out = open(argv[argc - 1], O_CREAT
				| O_APPEND | O_WRONLY, 0666);
		if (tool->curr_pipe_out == -1)
			print_error("open");
	}
	else
	{
		if (pipe(tool->fds) == -1)
			print_error("pipe");
		tool->curr_pipe_in = tool->fds[0];
		tool->curr_pipe_out = tool->fds[1];
	}
}

static void	execute_child(t_tool *tool, char **argv, t_list *cur_cmd, int i)
{
	char	*cmd;

	if (i == 0)
	{
		tool->prev_pipe_in = open(argv[1], O_RDONLY, 0666);
		if (tool->prev_pipe_in == -1)
			print_error("open");
	}
	if (dup2(tool->prev_pipe_in, 0) == -1)
		print_error("dup2");
	if (close(tool->prev_pipe_in) == -1)
		print_error("close");
	if (dup2(tool->curr_pipe_out, 1) == -1)
		print_error("dup2");
	if (close(tool->curr_pipe_out) == -1)
		print_error("close");
	cmd = check_valid_cmd(&tool->path_list, cur_cmd);
	if (!cmd)
		print_error("access");
	if (execve(cmd, cur_cmd->content, NULL) == -1)
		print_error("execve");
}

static void	pipex(t_tool *tool, int argc, char **argv)
{
	int		i;
	int		pid;
	t_list	*cur_cmd;

	i = -1;
	if (tool->heredoc == 1)
		cur_cmd = tool->cmd_list.head->next;
	else
		cur_cmd = tool->cmd_list.head;
	while (++i < tool->cmd_num)
	{
		set_pipe(tool, argc, argv, i);
		pid = fork();
		if (pid == -1)
			print_error("fork");
		if (pid == 0)
			execute_child(tool, argv, cur_cmd, i);
		if (tool->prev_pipe_in >= 0)
			close(tool->prev_pipe_in);
		tool->prev_pipe_in = tool->curr_pipe_in;
		close(tool->curr_pipe_out);
		cur_cmd = cur_cmd->next;
	}
	close(tool->prev_pipe_in);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_tool		tool;

	if (argc < 5)
	{
		write(2, "arg error\n", 10);
		exit(1);
	}
	init_tool(&tool, argc);
	get_path_list(&tool.path_list, envp);
	get_arg_list(&tool.cmd_list, argc, argv);
	if (check_heredoc(argv) == 1)
	{
		tool.heredoc = 1;
		tool.cmd_num -= 1;
		make_heredoc(argc, argv);
	}
	pipex(&tool, argc, argv);
	clear_list(&tool.cmd_list);
	clear_list(&tool.path_list);
	return (0);
}
