/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:12:24 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/25 16:53:40 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arguments	arg;

	if (check_args(argc, argv) == -1)
		return (write(2, "Error\nInvalid arguments\n", 24));
	if (initialize_arguments(&arg, argv) == -1)
		return (write(2, "Error\nArgument overflow detected\n", 33));
	if (arg.philo_num < 1 || arg.philo_num > 200 || arg.time_to_die < 1 || \
		arg.time_to_eat < 1 || arg.time_to_sleep < 1)
		return (write(2, "Error\nInvalid arguments\n", 24));
	if (arg.num_to_eat == 0)
		return (0);
	start_procces(&arg);
	return (0);
}
