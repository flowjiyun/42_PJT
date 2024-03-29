/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:26:57 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/01/18 13:25:22 by jiyunpar         ###   ########.fr       */
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
typedef struct s_time			t_time;

typedef struct s_input
{
	int				num_of_philo;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;	
}	t_input;

typedef struct s_time
{
	struct timeval	simulation_start_timeval;
	struct timeval	prev_eat_timeval;
}	t_time;

typedef struct s_shared_data
{
	pthread_mutex_t	start_flag_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	*fork_flag_lock;
	bool			is_philo_dead;
	pthread_mutex_t	dead_flag_lock;
	int				*num_of_meal;
	pthread_mutex_t	meal_count_lock;
}	t_shared_data;
typedef struct s_philo
{
	int				thread_id;
	pthread_t		*thread;
	t_shared_data	*shared_data;
	t_input			*input;
	t_time			*time;
}	t_philo;

bool			is_valid_input(char **argv);
t_input			*set_input(int argc, char **argv);
t_shared_data	*set_shared_data(t_input *input);
t_philo			**set_philo(t_shared_data *shared_data, t_input *input);
void			*routine(void *arg);
int				create_philo(t_philo **philo_arr, int num_of_philo);
int				destroy_mutex(t_shared_data *shared_data, int num_of_philo);
long			get_time_from_base(struct timeval base_timeval);
int				ft_usleep(useconds_t sleep_time);
void			free_all(t_philo **philo_arr, t_shared_data *shared_data,
					t_input *input);
int				wait_philo(t_philo **philo_arr, int philo_num);
int				print_status(t_philo *philo, int status);
int				monitoring(t_philo	**philo_arr, t_shared_data *shared_data,
					int num_of_philo, int argc);
int				sleeping(t_philo *philo);
int				eating(t_philo *philo);
int				thinking(t_philo *philo);
int				pickup_fork(t_philo *philo);
int				putdown_fork(t_philo *philo);
bool			is_died_after_pick_fork(t_philo *philo);
bool			is_died(t_philo *philo);

#endif