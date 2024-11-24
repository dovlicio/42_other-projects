/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:33:18 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 16:38:38 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	print_state(t_philos *th, char *str)
{
	pthread_mutex_lock(th->write_lock);
	pthread_mutex_lock(th->dead_lock);
	if (!th->dead)
		printf("%lu %d %s\n", get_time() - th->start_time, th->id, str);
	pthread_mutex_unlock(th->dead_lock);
	pthread_mutex_unlock(th->write_lock);
}

int	dead(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	set_all_dead(t_philos *th)
{
	int	i;

	i = 0;
	while (i < th[0].philo_num)
	{
		pthread_mutex_lock(th[0].dead_lock);
		th[i].dead = 1;
		pthread_mutex_unlock(th[0].dead_lock);
		i++;
	}
}
