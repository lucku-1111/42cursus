/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:04:07 by seoklee           #+#    #+#             */
/*   Updated: 2021/09/26 21:16:55 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int	bytes = 0;

	bytes++;
	if (sig == SIGUSR1)
	{
		write(1, "Receive bytes: ", 15);
		ft_putnbr(bytes);
		write(1, "\n", 1);
		exit(0);
	}
}

static void	send_char(pid_t server_pid, char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] >> j) & 1)
			{
				if (kill(server_pid, SIGUSR2) == -1)
					ft_error();
			}
			else
			{
				if (kill(server_pid, SIGUSR1) == -1)
					ft_error();
			}
			j++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		ft_error();
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100)
		ft_error();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_char(server_pid, argv[2], ft_strlen(argv[2]));
	while (1)
		pause();
	return (0);
}
