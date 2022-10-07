/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/07 16:52:06 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	check_heredoc(char **argv, t_list_info *path, t_list_info *cmd)
{
	char	*ret;

	if ((ft_strncmp(argv[1], "here_doc", 8) == 0)
		&& (ft_strlen(argv[1]) == ft_strlen("here_doc")))
	{
		ret = check_valid_cmd(path, cmd->head);
		if (!ret)
		{
			free(ret);
			return (1);
		}
		else
		{
			free(ret);
			return (0);
		}
	}
	return (0);
}

void	make_heredoc(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*c;

	fd = open("heredoc", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
		print_error();
	i = -1;
	while (1)
	{
		while (++i < argc - 5)
			write(1, "pipe ", 5);
		write(1, "heredoc> ", 9);
		c = get_next_line(0);
		if ((ft_strncmp(c, argv[1], ft_strlen(argv[1])) == 0)
			&& (ft_strlen(c) == ft_strlen(argv[1]) + 1))
			break ;
		write(fd, c, ft_strlen(c));
	}
	close(fd);
}
