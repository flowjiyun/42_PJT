/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:45 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/04 13:34:23 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_list_info path_list; // list of char * 
	t_list_info cmd_list; // list of char **

	if (argc < 5)
	{
		write(2, "Not Enough Arguments\n", 21);
		exit(1);
	}
	init_list(&path_list);
	init_list(&cmd_list);
	get_path_list(&path_list, envp);
	get_arg_list(&cmd_list, argv);
	// while (cmd_list.head)
	// {
	// 	printf("%s\n", ((char **)cmd_list.head->content)[0]);
	// 	cmd_list.head = cmd_list.head->next;
	// }
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
