/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:26:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/12 10:33:35 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

# define HAS_FORK_MESSAGE "%ld %d has taken a fork\n"
# define EATING_MESSAGE "%ld %d is eating\n"
# define SLEEPING_MESSAGE "%ld %d is sleeping\n"
# define THINKING_MESSAGE "%ld %d is thinking\n"
# define DIED_MESSAGE "%ld %d died\n"

enum
{
	HAS_FORK = 0,
	EATING,
	SLEEPING,
	THINKING,
	DIED
};

typedef struct s_shared_data	t_shared_data;
typedef struct s_input			t_input;

typedef struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;	
}	t_input;

typedef struct s_shared_data
{
	bool			*is_philo_created;
	pthread_mutex_t	created_flag_lock;
	bool			*is_fork_occupied;
	pthread_mutex_t	*fork_flag_lock;
	bool			*is_philo_dead;
	pthread_mutex_t	dead_flag_lock;
	int				*num_of_meal;
	pthread_mutex_t	meal_count_lock;
	bool			start_flag;
	pthread_mutex_t	start_flag_lock;
}	t_shared_data;
typedef struct s_philo
{
	int				thread_id;
	pthread_t		*thread;
	t_shared_data	*shared_data;
	t_input			*input;
	struct timeval	simulation_start_timeval;
	struct timeval	prev_eat_timeval;
}	t_philo;

bool			is_valid_input(char **argv);
t_input			*set_input(int argc, char **argv);
t_shared_data	*set_shared_data(t_input *input);
t_philo			**set_philo(t_shared_data *shared_data, t_input *input);
void			*routine(void *arg);
bool			create_philo(t_philo **philo_arr, int num_of_philo);
bool			terminate_philo(t_philo **philo_arr, int num_of_philo);
bool			wait_philo(t_philo **philo_arr, int num_of_philo);
bool			destroy_mutex(t_shared_data *shared_data, int num_of_philo);
bool			is_all_philo_created(t_shared_data *shared_data,
					int num_of_philo);

#endif