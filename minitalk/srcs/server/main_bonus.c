/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:04:09 by seoklee           #+#    #+#             */
/*   Updated: 2021/09/26 21:01:44 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_handler(int sig, siginfo_t *info, void *unused)
{
	static t_msg	msg;

	(void)unused;
	msg.c += (sig & 1) << msg.size;
	msg.size++;
	if (msg.size == 8)
	{
		write(1, &msg.c, 1);
		if (msg.c == 0)
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_error();
		}
		else
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_error();
		msg.c = 0;
		msg.size = 0;
	}
}

int	main(void)
{
	struct sigaction	info;

	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = signal_handler;
	write(1, "server pid: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &info, 0);
	sigaction(SIGUSR2, &info, 0);
	while (1)
		pause();
	return (0);
}
