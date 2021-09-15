/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:18:24 by fbafica           #+#    #+#             */
/*   Updated: 2021/09/13 13:05:18 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "ft_printf.h"

int		g_flag;
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
int		client(int pid, char *s);
int		server(void);

#endif