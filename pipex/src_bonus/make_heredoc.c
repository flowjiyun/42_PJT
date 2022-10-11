/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/10/11 15:39:10 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_heredoc(char **argv)
{
	if ((ft_strncmp(argv[1], "here_doc", 8) == 0)
		&& (ft_strlen(argv[1]) == ft_strlen("here_doc")))
		return (1);
	else
		return (0);
}

void	make_heredoc(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*c;

	fd = open("here_doc", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd == -1)
		print_error("open");
	while (1)
	{
		i = -1;
		while (++i < argc - 5)
			write(1, "pipe ", 5);
		write(1, "heredoc> ", 9);
		c = get_next_line(0);
		if ((ft_strncmp(c, argv[2], ft_strlen(argv[2])) == 0)
			&& (ft_strlen(c) == ft_strlen(argv[2]) + 1))
			break ;
		write(fd, c, ft_strlen(c));
	}
	close(fd);
}
