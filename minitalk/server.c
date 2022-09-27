/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:09:49 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/27 14:09:41 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sigtool	sigtool;

static void	recd_one_bit(int signum, siginfo_t *info, void *context)
{	
	(void)context;
	sigtool.byte |= 1;
	sigtool.byte <<= 1;
	sigtool.count++;
	if (sigtool.count == 8)
	{
		sigtool.byte >>= 1;
		write(1, &sigtool.byte, 1);
		sigtool.byte = 0;
		sigtool.count = 0;
	}
	usleep(30);
	if (kill(info->si_pid, signum))
		put_error();
}

static void	recd_zero_bit(int signum, siginfo_t *info, void *context)
{	
	(void)context;
	sigtool.byte <<= 1;
	sigtool.count++;
	if (sigtool.count == 8)
	{
		sigtool.byte >>= 1;
		write(1, &sigtool.byte, 1);
		sigtool.byte = 0;
		sigtool.count = 0;
	}
	usleep(30);
	if (kill(info->si_pid, signum))
		put_error();
}

static void	set_sigact(struct sigaction *zero_act, struct sigaction *one_act)
{
	sigemptyset(&(zero_act->sa_mask));
	sigemptyset(&(one_act->sa_mask));
	zero_act->sa_flags = SA_SIGINFO;
	one_act->sa_flags = SA_SIGINFO;
	zero_act->sa_sigaction = recd_zero_bit;
	one_act->sa_sigaction = recd_one_bit;
	sigaction(SIGUSR1, zero_act, 0);
	sigaction(SIGUSR2, one_act, 0);
}

int	main(void)
{
	set_sigact(&sigtool.zero_act, &sigtool.one_act);
	sigtool.count = 0;
	sigtool.pid = getpid();
	ft_putnbr(sigtool.pid);
	while (1)
	{
		pause();
	}
}
