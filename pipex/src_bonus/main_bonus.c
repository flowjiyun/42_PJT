/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/12 13:41:11 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (unlink("here_doc") == -1)
		print_error("unlink");
	clear_list(&tool.cmd_list);
	clear_list(&tool.path_list);
	return (0);
}
