/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:10:22 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/03 00:55:34 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_info *info)
{
	int				i;

	i = 0;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->num);
	if (!info->fork)
		return ;
	info->fork_status = malloc(sizeof(int) * info->num);
	if (!info->fork_status)
		return ;
	while (i < info->num)
	{
		info->fork_status[i] = 0;
		if (pthread_mutex_init(&(info->fork[i++]), NULL))
			return ;
	}
}

void	init_philo(t_info *info)
{
	int		i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->num);
	if (!info->philo)
		return ;
	while (i < info->num)
	{
		info->philo[i].id = i + 1;
		info->philo[i].eat_count = 0;
		info->philo[i].eat = 0;
		info->philo[i].last_eat = get_time();
		info->philo[i].thread = 0;
		info->philo[i].l_fork = &(info->fork[i]);
		info->philo[i].l_fork_status = &(info->fork_status[i]);
		info->philo[i].r_fork = &(info->fork[(i + 1) % info->num]);
		info->philo[i].r_fork_status = &(info->fork_status[(i + 1) % info->num]);
		info->philo[i++].info = info;
	}
}

int	init_info(t_info *info, int ac, char **av)
{
	info->num = ft_atoi(av[1]);
	info->die_t = ft_atoi(av[2]);
	info->eat_t = ft_atoi(av[3]);
	info->sleep_t = ft_atoi(av[4]);
	info->must_eat = 0;
	if (ac == 6)
	{
		info->must_eat = ft_atoi(av[5]);
		if (info->must_eat < 1)
			return (1);
	}
	info->start_t = get_time();
	info->finish = 0;
	init_fork(info);
	init_philo(info);
	if (info->num < 1 || info->die_t <= 0 || info->eat_t < 0 \
		|| info->sleep_t < 0 || !info->fork || !info->philo \
		|| pthread_mutex_init(&(info->print_m), NULL) \
		|| pthread_mutex_init(&(info->finish_m), NULL) \
		|| pthread_mutex_init(&(info->last_eat_m), NULL) \
		|| pthread_mutex_init(&(info->eat_count_m), NULL))
		return (1);
	return (0);
}
