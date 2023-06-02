/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:16:06 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/02 14:43:17 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (print_err("Invalid arguments."));
	if (init_info(&info, ac, av))
		return (print_err("Init fail."));
	if (start_threads(&info))
		return (print_err("pthread_create fail."));
	check_finish(&info);
	if (end_threads(&info))
		return (print_err("pthread_join fail."));
	free_info(&info);
	return (0);
}
