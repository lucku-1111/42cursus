/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:04:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/29 22:28:09 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_info info, int id, char *msg)
{
	if (info.finish_eat != info.num && info.someone_died == 0)
		printf("%lld %d %s\n", get_time() - info.start_t, id, msg);
}

int	print_err(char *err_msg)
{
	printf("Error.\n%s\n", err_msg);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (*str != '\0')
		return (-1);
	return ((long long)result * sign);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		now;

	if (gettimeofday(&time, NULL))
		return (0);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

void	spend_time(long long time)
{
	long long	start;
	long long	now;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start >= time)
			break;
		usleep(10);
	}
}
