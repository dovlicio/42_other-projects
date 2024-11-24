/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:40:07 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 16:54:12 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>

typedef struct s_arguments
{
	int		philo_num;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_to_eat;
}				t_arguments;

typedef struct s_philos
{
	pthread_t		th;
	int				id;
	int				philo_num;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			last_meal;
	int				num_to_eat;
	int				meals_eaten;
	int				dead;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*philo_lock;
}				t_philos;

/*--------------------------ARGUMENTS----------------------*/
int		check_args(int argc, char **argv);
int		initialize_arguments(t_arguments *arg, char **argv);

/*---------------------------THREADS-----------------------*/
void	*run_thread(void *th);
void	*supervisor(void *philos);
int		start_procces(t_arguments *arg);
void	fill_threads_struct(t_philos *th, t_arguments *arg, \
			pthread_mutex_t	*forks, pthread_mutex_t	*locks);

/*---------------------------UTILS-------------------------*/
size_t	get_time(void);
int		ft_usleep(size_t milliseconds);
void	print_state(t_philos *th, char *str);
int		dead(t_philos *philo);
void	set_all_dead(t_philos *th);
void	destroy_mutexes(pthread_mutex_t *forks, pthread_mutex_t *locks, \
			t_arguments *arg);
void	create_threads(pthread_mutex_t	*forks, pthread_mutex_t	*locks, \
			t_philos *th, t_arguments *arg);

#endif
