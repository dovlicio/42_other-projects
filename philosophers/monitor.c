/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:41:35 by vdamnjan          #+#    #+#             */
/*   Updated: 2024/02/17 15:41:18 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_is_dead(t_philos *th)
{
	int	i;

	i = 0;
	while (i < th[0].philo_num)
	{
		pthread_mutex_lock(th[0].philo_lock);
		if (get_time() - th[i].last_meal >= th[i].time_to_die)
		{
			pthread_mutex_unlock(th[0].philo_lock);
			print_state(&th[i], "died");
			i = 0;
			while (i < th[0].philo_num)
			{
				pthread_mutex_lock(th[0].dead_lock);
				th[i].dead = 1;
				pthread_mutex_unlock(th[0].dead_lock);
				i++;
			}
			return (1);
		}
		pthread_mutex_unlock(th[0].philo_lock);
		i++;
	}
	return (0);
}

static int	eaten_all_meals(t_philos *th)
{
	int	i;
	int	finished;

	if (th[0].num_to_eat == -1)
		return (0);
	i = 0;
	finished = 0;
	while (i < th[0].philo_num)
	{
		pthread_mutex_lock(th[0].philo_lock);
		if (th[i].meals_eaten >= th[0].num_to_eat)
			finished++;
		pthread_mutex_unlock(th[0].philo_lock);
		i++;
	}
	if (finished >= th[0].philo_num)
	{
		set_all_dead(th);
		return (1);
	}
	return (0);
}

void	*supervisor(void *philos)
{
	t_philos	*th;

	th = (t_philos *)philos;
	while (1)
	{
		if (philo_is_dead(th) || eaten_all_meals(th))
			return (NULL);
	}
	return (NULL);
}
