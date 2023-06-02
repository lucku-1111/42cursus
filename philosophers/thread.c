/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:14:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/02 14:49:56 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
		if (pthread_join(info->philo[i++].thread, NULL))
			return (1);
	return (0);
}

void	check_finish(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = info->philo;
	while (info->finish_eat != info->num)
	{
		i = 0;
		while (i < info->num)
		{
			if (get_time() - philo[i].last_eat > info->die_t)
			{
				info->someone_died = 1;
				print_msg(*info, philo[i].id, "died");
				info->finish_eat = info->num;
				break ;
			}
			i++;
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		spend_time(info->eat_t * 0.9);
	while (info->someone_died == 0)
	{
		if (philo_eat(philo, info))
			break ;
		if (philo->eat_count == info->must_eat)
			info->finish_eat++;
		if (info->num == 1)
			break ;
		if (philo_sleep(philo, info))
			break ;
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&(info->print));
	return (0);
}

int	start_threads(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = info->philo;
	while (i < info->num)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (1);
		i++;
	}
	return (0);
}
