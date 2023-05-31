/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:20:01 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/01 04:16:34 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(philo->l_fork);
	if (info->someone_died)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	print_msg(*info, philo->id, "has taken a fork");
	if (info->num > 1)
	{
		pthread_mutex_lock(philo->r_fork);
		if (info->someone_died)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			return (1);
		}
		print_msg(*info, philo->id, "has taken a fork");
		print_msg(*info, philo->id, "is eating");
		philo->last_eat = get_time();
		spend_time(info->eat_t);
		philo->eat_count++;
		pthread_mutex_unlock(philo->r_fork);
	}
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}

int	philo_sleep(t_philo *philo, t_info *info)
{
	if (info->someone_died)
		return (1);
	print_msg(*info, philo->id, "is sleeping");
	spend_time(info->sleep_t);
	if (info->someone_died)
		return (1);
	print_msg(*info, philo->id, "is thinking");
	return (0);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->finish_check);
	free(info->fork);
	free(info->philo);
}
