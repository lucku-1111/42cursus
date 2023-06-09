/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:17:08 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/05 15:47:59 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				eat_count;
	long long		last_eat;
	pthread_t		thread;
	int				*l_fork_status;
	int				*r_fork_status;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
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
	int				finish;
	int				*fork_status;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_m;
	pthread_mutex_t	finish_m;
	pthread_mutex_t	last_eat_m;
	pthread_mutex_t	eat_count_m;
}	t_info;

int				init_info(t_info *info, int ac, char **av);
void			init_philo(t_info *info);
void			init_fork(t_info *info);

int				start_threads(t_info *info);
void			*routine(void *arg);
int				end_threads(t_info *info);

void			check_finish(t_info *info);
int				stop(t_info *info);
int				check_eat(t_info *info);
void			finish_flag(t_info *info);
long long		get_last_eat(t_philo *philo);

int				get_forks(t_philo *philo, t_info *info);
int				philo_eat(t_philo *philo, t_info *info);
int				philo_sleep(t_philo *philo, t_info *info);
void			free_info(t_info *info);

void			print_msg(t_info *info, int id, char *msg);
int				print_err(char *err_msg);
int				ft_atoi(const char *str);
long long		get_time(void);
void			spend_time(long long time);

#endif
