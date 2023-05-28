/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:17:08 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/28 20:12:12 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		last_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num;
	long long		die_t;
	long long		eat_t;
	long long		sleep_t;
	int				must_eat;
	long long		start_t;
	int				finish_eat;
	int				someone_died;
	t_philo			*philo;
	pthread_mutex_t	*fork;
}	t_info;

int	print_err(char *err_msg);
int	ft_atoi(const char *str);
int	init_info(t_info *info, int ac, char **av);
pthread_mutex_t	*init_fork(int num);
t_philo	*init_philo(t_info *info);
long long	get_time(void);
int	ft_threads(t_info info);
void	*routine(void *arg);
void	spend_time(long long time);
void	print_msg(long long time, int id, char *msg);

#endif