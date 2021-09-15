/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:17:33 by fbafica           #+#    #+#             */
/*   Updated: 2021/09/13 23:30:48 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag -= 1;
	if (g_flag == 0)
		ft_printf("%s\n", "The message has been sent");
}

void	send_signal(int pid, char c)
{
	char	mask;
	int		i;

	signal(SIGUSR1, handler);
	i = 0;
	while (i < 8)
	{
		mask = c >> i;
		if (mask & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		++i;
		usleep(1500);
	}
}

int	client(int pid, char *s)
{
	int	i;

	g_flag = ((ft_strlen(s) + 1) * 8);
	i = 0;
	while (s[i] != '\0')
	{
		send_signal(pid, s[i]);
		++i;
	}
	send_signal(pid, '\n');
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
