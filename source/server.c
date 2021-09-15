/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:19:06 by fbafica           #+#    #+#             */
/*   Updated: 2021/09/13 23:28:34 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	index;
	static char	byte;
	char		mask;

	if (sig == SIGUSR1)
	{
		mask = 1 << index;
		byte = byte | mask;
	}
	if (sig == SIGUSR2)
	{
		mask = 1 << index;
		byte = byte & ~mask;
	}
	index += 1;
	if (index == 8)
	{
		ft_printf("%c", byte);
		index = 0;
	}
	ucontext = ucontext;
	kill(info->si_pid, SIGUSR1);
}

int	server(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

int	main(void)
{
	server();
	return (0);
}
