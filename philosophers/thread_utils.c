/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:20:01 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/03 00:51:49 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_forks(t_philo *philo, t_info *info)
{
	if (info->num == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		*(philo->l_fork_status) = 1;
		print_msg(info, philo->id, "has taken a fork");
		*(philo->l_fork_status) = 0;
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	pthread_mutex_lock(philo->l_fork);
	*(philo->l_fork_status) = 1;
	print_msg(info, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	*(philo->r_fork_status) = 1;
	print_msg(info, philo->id, "has taken a fork");
	return (0);
}

int	philo_eat(t_philo *philo, t_info *info)
{
	if (stop(info))
	{
		*(philo->l_fork_status) = 0;
		pthread_mutex_unlock(philo->l_fork);
		*(philo->r_fork_status) = 0;
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	print_msg(info, philo->id, "is eating");
	pthread_mutex_lock(&(info->last_eat_m));
	philo->last_eat = get_time();
	pthread_mutex_unlock(&(info->last_eat_m));
	pthread_mutex_lock(&(info->eat_count_m));
	philo->eat_count++;
	pthread_mutex_unlock(&(info->eat_count_m));
	spend_time(info->eat_t);
	*(philo->l_fork_status) = 0;
	pthread_mutex_unlock(philo->l_fork);
	*(philo->r_fork_status) = 0;
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	philo_sleep(t_philo *philo, t_info *info)
{
	if (stop(info))
		return (1);
	print_msg(info, philo->id, "is sleeping");
	spend_time(info->sleep_t);
	if (stop(info))
		return (1);
	print_msg(info, philo->id, "is thinking");
	return (0);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->print_m));
	pthread_mutex_destroy(&(info->finish_m));
	pthread_mutex_destroy(&(info->last_eat_m));
	pthread_mutex_destroy(&(info->eat_count_m));
	free(info->fork);
	free(info->fork_status);
	free(info->philo);
}
