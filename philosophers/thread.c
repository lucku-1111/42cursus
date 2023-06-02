/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:14:43 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/02 23:55:44 by seoklee          ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		spend_time(info->eat_t * 0.9);
	while (!stop(info))
	{
		if (get_forks(philo, info))
			break ;
		if (philo_eat(philo, info))
			break ;
		if (philo_sleep(philo, info))
			break ;
	}
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
