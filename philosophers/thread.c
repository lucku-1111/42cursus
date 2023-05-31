/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:14:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/01 04:30:57 by seoklee          ###   ########.fr       */
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
		usleep(500);
	while (info->finish_eat != info->num)
	{
		if (info->someone_died == 1)
			break ;
		if (philo_eat(philo, info))
			break ;
		if (philo->eat_count == info->must_eat)
			info->finish_eat++;
		if (info->num == 1)
			break ;
		if (philo_sleep(philo, info))
			break ;
	}
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
	while (!info->someone_died && info->finish_eat != info->num)
	{
		i = 0;
		while (i < info->num)
		{
			if (get_time() - philo[i].last_eat > info->die_t)
			{
				pthread_mutex_lock(&(info->finish_check));
				print_msg(*info, philo[i].id, "died");
				info->someone_died = 1;
				pthread_mutex_unlock(&(info->finish_check));
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
