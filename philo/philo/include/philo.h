/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:26:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/05 21:03:50 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include "libft.h"

enum
{
	HUNGRY = 0,
	EATING,
	THINKING,
	SLEEPING
};

typedef struct s_fork	t_fork;
typedef struct s_input	t_input;

typedef struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;	
}	t_input;

typedef struct s_fork
{
	bool			*is_occupied;
	pthread_mutex_t	usaged_lock;
}	t_fork;

typedef struct s_philo
{
	pthread_t		*philosophers;
	int				*state;
	pthread_mutex_t	state_lock;
	t_fork			*fork;
	t_input			*input;
}	t_philo;

bool	is_valid_input(char **argv);
bool	set_input(t_input *input, int argc, char **argv);
bool	set_fork(t_fork *fork, t_input *input);
bool	set_philo(t_philo *philo, t_fork *fork, t_input *input);
void	*routine(void *arg);
bool	create_philo(t_philo *philo);
bool	wait_philo(t_philo *philo);

#endif