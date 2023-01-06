/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:26:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/06 17:05:39 by jiyunpar         ###   ########.fr       */
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

typedef struct s_meal
{
	int				*num_of_meal;
	pthread_mutex_t	count_lock;
}	t_meal;

typedef struct s_philo
{
	int				thread_id;
	pthread_t		*thread;
	t_fork			*fork;
	t_input			*input;
}	t_philo;

bool	is_valid_input(char **argv);
t_input	*set_input(int argc, char **argv);
t_fork	*set_fork(t_input *input);
t_philo	**set_philo(t_fork *fork, t_input *input);
void	*routine(void *arg);
bool	create_philo(t_philo **philo_arr, int num_of_philo);
bool	wait_philo(t_philo **philo_arr, int num_of_philo);

#endif