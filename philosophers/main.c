/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:16:06 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/01 21:29:23 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 5 && ac != 6)
		return (print_err("Invalid arguments."));
	if (!init_info(&info, ac, av))
		return (print_err("Init fail."));
	if (!ft_threads(&info))
		return (print_err("Ft_threads fail."));
	return (0);
}
