/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/30 19:44:36 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list_info path_list;
	// t_list_info cmd_list;

	(void)argc;
	(void)argv;
	init_list(&path_list);
	get_path_list(&path_list, envp);
	while (path_list.head)
	{
		printf("%s\n", (char *)path_list.head->content);
		path_list.head = path_list.head->next;
	}

	return (0);
}


	// int command_num;

	// command_num = 10;

	// int fdin;
	// fdin = open("infile", O_CREAT | O_RDONLY);

	// int ret;
	// int fdout;
	// int i;

	// i = 0;
	// while (i < command_num)
	// {
	// 	dup2(fdin, 0); // redirect input 
	// 	close(fdin); // 0
	// 	if (i == command_num - 1)
	// 		fdout = open("outfile", O_CREAT | O_WRONLY);
	// 	else
	// 	{
	// 		int fdpipe[2];
	// 		pipe(fdpipe);
	// 		fdout = fdpipe[1];
	// 		fdin = fdpipe[0];
	// 	}
	// 	dup2(fdout, 1);
	// 	close(fdout);

	// 	ret = fork();
	// 	//child
	// 	if (ret == 0)
	// 	{
	// 		//execve(parsing argument);
	// 	}	
	// 	i++;
	// }
	// waitpid(ret, NULL);
