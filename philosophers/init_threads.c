/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:03 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 16:51:57 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_routine_odd(t_philos *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_state(philo, "has taken a fork");
	if (philo->philo_num == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_state(philo, "has taken a fork");
	print_state(philo, "is eating");
	pthread_mutex_lock(philo->philo_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->philo_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_state(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	print_state(philo, "is thinking");
	ft_usleep(1);
}

static void	start_routine_even(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print_state(philo, "has taken a fork");
	print_state(philo, "is eating");
	pthread_mutex_lock(philo->philo_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->philo_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	print_state(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	print_state(philo, "is thinking");
	ft_usleep(1);
}

void	*run_thread(void *th)
{
	t_philos	*philo;

	philo = (t_philos *)th;
	while (1)
	{
		if (dead(philo))
			break ;
		if (philo->id % 2 == 0)
			start_routine_odd(philo);
		else
			start_routine_even(philo);
	}
	return (th);
}

void	fill_threads_struct(t_philos *th, t_arguments *arg, \
			pthread_mutex_t	*forks, pthread_mutex_t	*locks)
{
	unsigned long long	start_time;
	int					i;

	i = 0;
	start_time = get_time();
	while (i < arg->philo_num)
	{
		th[i].id = i;
		th[i].philo_num = arg->philo_num;
		th[i].time_to_die = arg->time_to_die;
		th[i].time_to_eat = arg->time_to_eat;
		th[i].time_to_sleep = arg->time_to_sleep;
		th[i].num_to_eat = arg->num_to_eat;
		th[i].start_time = start_time;
		th[i].last_meal = start_time;
		th[i].dead = 0;
		th[i].meals_eaten = 0;
		th[i].l_fork = &forks[i];
		th[i].r_fork = &forks[(i - 1 + th[i].philo_num) % th[i].philo_num];
		th[i].write_lock = &locks[0];
		th[i].philo_lock = &locks[1];
		th[i].dead_lock = &locks[2];
		i++;
	}
}

int	start_procces(t_arguments *arg)
{
	t_philos		th[201];
	pthread_mutex_t	forks[201];
	pthread_mutex_t	locks[3];
	pthread_t		monitor;
	int				i;

	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < 3)
		pthread_mutex_init(&locks[i++], NULL);
	fill_threads_struct(th, arg, forks, locks);
	if (pthread_create(&monitor, NULL, &supervisor, th) != 0)
		destroy_mutexes(forks, locks, arg);
	create_threads(forks, locks, th, arg);
	if (pthread_join(monitor, NULL) != 0)
		destroy_mutexes(forks, locks, arg);
	i = 0;
	while (i < arg->philo_num)
		if (pthread_join(th[i++].th, NULL) != 0)
			destroy_mutexes(forks, locks, arg);
	destroy_mutexes(forks, locks, arg);
	return (0);
}
