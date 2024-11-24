/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:13:37 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 13:48:10 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned long long	ft_atol(const char *nptr)
{
	long long	result;
	int			add1;
	int			add2;

	result = 0;
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		add1 = result * 10;
		add2 = (*nptr++ - '0');
		result = add1 + add2;
		if (result - add2 != add1)
			return (-1);
	}
	return (result);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (-1);
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '+')
			j++;
		if (argv[i][j] == '0' && argv[i][j + 1])
			return (-1);
		if (argv[i][j] < '0' && argv[i][j] > '9')
			return (-1);
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
			j++;
		if (argv[i][j])
			return (-1);
		i++;
	}
	return (0);
}

int	initialize_arguments(t_arguments *arg, char **argv)
{
	int	overflow_check;
	int	i;

	i = 1;
	while (argv[i])
	{
		overflow_check = (int)ft_atol(argv[i++]);
		if (overflow_check == -1)
			return (-1);
	}
	arg->philo_num = (int)ft_atol(argv[1]);
	arg->time_to_die = ft_atol(argv[2]);
	arg->time_to_eat = ft_atol(argv[3]);
	arg->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		arg->num_to_eat = (int)ft_atol(argv[5]);
	else
		arg->num_to_eat = -1;
	return (0);
}
