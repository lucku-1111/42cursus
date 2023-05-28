/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:14:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/28 20:35:24 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->l_fork);
	print_msg(get_time() - info->start_t, philo->id, "has taken a fork");
	if (info->num > 1)
	{
		pthread_mutex_lock(&philo->r_fork);
		print_msg(get_time() - info->start_t, philo->id, "has taken a fork");
		print_msg(get_time() - info->start_t, philo->id, "is eating");
		spend_time(info->eat_t);
		philo->last_eat = get_time();
		philo->eat_count++;
		pthread_mutex_unlock(&philo->r_fork);
	}
	pthread_mutex_unlock(&philo->l_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(10);
	while (info->finish_eat != info->num && info->someone_died == 0)
	{
		philo_eat(philo, info);
		if (philo->eat_count == info->must_eat)
			info->finish_eat++;
		print_msg(get_time() - info->start_t, philo->id, "is sleeping");
		spend_time(info->sleep_t);
		print_msg(get_time() - info->start_t, philo->id, "is thinking");
	}
	return (0);
}

void	is_finish(t_info *info)
{
	int		i;
	t_philo	*philo;

	philo = info->philo;
	while (1)
	{
		if (info->finish_eat == info->num)
			break ;
		i = 0;
		while (i < info->num)
		{
			if (get_time() - philo[i].last_eat >= info->die_t)
			{
				info->someone_died = i;
				break ;
			}
			i++;
		}
		if (info->someone_died != 0)
		{
			print_msg(get_time() - info->start_t, info->someone_died + 1, "is died");
			break ;
		}
	}
}

void	free_info(t_info info)
{
	int	i;

	i = 0;
	while (i < info.num)
	{
		pthread_mutex_destroy(&info.fork[i]);
		i++;
	}
	free(info.fork);
	free(info.philo);
}

int	ft_threads(t_info info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = info.philo;
	while (i < info.num)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		i++;
	}
	is_finish(&info);
	i = 0;
	while (i < info.num)
		if (!pthread_join(philo[i++].thread, NULL))
			return (0);
	free_info(info);
	return (1);
}