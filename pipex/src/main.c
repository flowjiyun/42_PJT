/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:11:22 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/12 11:10:05 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_tool		tool;

	if (argc != 5)
	{
		write(2, "arg error\n", 10);
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
