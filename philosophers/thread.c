/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:14:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/01 21:56:27 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_threads(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = info->philo;
	while (i < info->num)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		i++;
	}
	while (1)
	{
		if (info->finish_eat == info->num)
			break ;
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
	i = 0;
	while (i < info->num)
		if (pthread_join(philo[i++].thread, NULL))
			return (0);
	free_info(info);
	return (1);
}
