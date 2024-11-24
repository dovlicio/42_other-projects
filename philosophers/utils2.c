/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:52:56 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 16:53:42 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(pthread_mutex_t *forks, pthread_mutex_t *locks, \
			t_arguments *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
		pthread_mutex_destroy(&forks[i++]);
	i = 0;
	while (i < 3)
		pthread_mutex_destroy(&locks[i++]);
}

void	create_threads(pthread_mutex_t	*forks, pthread_mutex_t	*locks, \
			t_philos *th, t_arguments *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_num)
	{
		if (pthread_create(&th[i].th, NULL, &run_thread, &th[i]) != 0)
			destroy_mutexes(forks, locks, arg);
		i++;
	}
}
