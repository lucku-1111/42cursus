/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 23:54:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/02 23:56:41 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_last_eat(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&(philo->info->last_eat_m));
	time = philo->last_eat;
	pthread_mutex_unlock(&(philo->info->last_eat_m));
	return (time);
}

void	finish_flag(t_info *info)
{
	pthread_mutex_lock(&(info->finish_m));
	info->finish = 1;
	pthread_mutex_unlock(&(info->finish_m));
}

int	check_eat(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = info->philo;
	i = 0;
	while (i < info->num)
	{
		pthread_mutex_lock(&(info->eat_count_m));
		if (philo[i].eat_count < info->must_eat)
			{
				pthread_mutex_unlock(&(info->eat_count_m));
				return (0);
			}
		pthread_mutex_unlock(&(info->eat_count_m));
		i++;
	}
	return (1);
}

int	stop(t_info *info)
{
	pthread_mutex_lock(&(info->finish_m));
	if (info->finish == 1)
	{
		pthread_mutex_unlock(&(info->finish_m));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(info->finish_m));
		return (0);
	}
}

void	check_finish(t_info *info)
{
	int		i;
	t_philo *philo;

	philo = info->philo;
	while (!stop(info))
	{
		if (info->must_eat != 0 && check_eat(info))
		{
			finish_flag(info);
			break ;
		}
		i = 0;
		while (i < info->num)
		{
			if (get_time() - get_last_eat(&philo[i]) > info->die_t)
			{
				print_msg(info, i + 1, "died");
				finish_flag(info);
				break ;
			}
			i++;
		}
		usleep(10);
	}
}
