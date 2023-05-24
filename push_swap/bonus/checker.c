/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:25:18 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 16:00:37 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		operation(t_info *info, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ra(info);
	else if (ft_strcmp(line, "rb") == 0)
		rb(info);
	else if (ft_strcmp(line, "rr") == 0)
		rr(info);
	else if (ft_strcmp(line, "rra") == 0)
		rra(info);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(info);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(info);
	else if (ft_strcmp(line, "sa") == 0)
		sa(info);
	else if (ft_strcmp(line, "sb") == 0)
		sb(info);
	else if (ft_strcmp(line, "ss") == 0)
		ss(info);
	else if (ft_strcmp(line, "pa") == 0)
		pa(info);
	else if (ft_strcmp(line, "pb") == 0)
		pb(info);
	else
		return (0);
	return (1);
}

static void		start_sort(t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!operation(info, line))
		{
			go_error();
			free(line);
			exit(1);
		}
		free(line);
	}
	free(line);
}

static int	check_sort_a(t_info *info, int size)
{
	int idx;

	idx = info->a_top - size + 1;
	while (idx < info->a_top)
	{
		if (info->a[idx] < info->a[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void			checker(int argc, char *argv[])
{
	t_info info;

	setnum(&info, argc, argv);
	start_sort(&info);
	if (info.b_top == -1 && check_sort_a(&info, info.size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(info.a);
	free(info.b);
}