/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:16:06 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/29 10:00:31 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!init_info(&info, ac, av))
		return (print_err("Init fail."));
	if (!ft_threads(&info))
		return (print_err("Ft_threads fail."));
}
