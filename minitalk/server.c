/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:13:24 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/24 14:42:45 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_client_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static int		character;
	static pid_t	pid;
	static char		str[150000];
	static int		len;

	(void)context;
	if (pid != info->si_pid)
	{
		bit = 0;
		character = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR1)
		character += 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (character == 10)
		{
			write(1, str, len);
			len = 0;
		}
		str[len++] = (char)character;
		character = 0;
		bit = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (write(2, "Error: Run the program without arguments.\n", 42));
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_client_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
