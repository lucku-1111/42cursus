/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:10:22 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/03 00:00:18 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_fork(int num)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * num);
	if (!fork)
		return (0);
	while (i < num)
	{
		if (pthread_mutex_init(&fork[i++], NULL))
			return (0);
	}
	return (fork);
}

t_philo	*init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * info->num);
	if (!philo)
		return (0);
	while (i < info->num)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].eat = 0;
		philo[i].last_eat = get_time();
		philo[i].thread = 0;
		philo[i].l_fork = &info->fork[i];
		philo[i].r_fork = &info->fork[(i + 1) % info->num];
		philo[i].info = info;
		i++;
	}
	return (philo);
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
			return (0);
	}
	info->start_t = get_time();
	info->finish = 0;
	info->fork = init_fork(info->num);
	info->philo = init_philo(info);
	if (info->num < 1 || info->die_t <= 0 || info->eat_t < 0 \
		|| info->sleep_t < 0 || !info->fork || !info->philo \
		|| pthread_mutex_init(&(info->print_m), NULL)
		|| pthread_mutex_init(&(info->finish_m), NULL)
		|| pthread_mutex_init(&(info->last_eat_m), NULL)
		|| pthread_mutex_init(&(info->eat_count_m), NULL))
		return (1);
	return (0);
}
