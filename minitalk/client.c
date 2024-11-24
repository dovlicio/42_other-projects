/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:11:40 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/18 12:17:06 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sigusr(pid_t pid, int n)
{
	if (n == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(2, "Error: Wrong pid.\n", 18);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(2, "Error: Wrong pid.\n", 18);
			exit(EXIT_FAILURE);
		}
	}
}

void	send_signal(pid_t pid, char *string)
{
	static int	bit;
	static char	*copy;
	static int	end;

	if (string)
		copy = string;
	if (bit == 8)
	{
		bit = 0;
		copy++;
		if (!*copy && end == 1)
			exit(0);
		else if (!*copy)
		{
			end = 1;
			send_signal(pid, "\n\0");
		}
	}
	if ((*copy & (1 << bit)))
		send_sigusr(pid, 1);
	else
		send_sigusr(pid, 2);
	bit++;
}

void	handle_server_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		send_signal(info->si_pid, NULL);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	if (argc != 3)
		return (write(2, "Invalid number of arguments.\n", 29));
	if (argv[1][0] < '0' || argv[1][0] > '9')
		return (write(2, "Error: Wrong pid.\n", 18));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_server_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
