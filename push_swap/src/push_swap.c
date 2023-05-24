/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:49:13 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/06 16:00:22 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	check_sort_b(t_info *info, int size)
{
	int idx;

	idx = info->b_top - size + 1;
	while (idx < info->b_top)
	{
		if (info->b[idx] > info->b[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void		a_to_b(t_info *info, int size)
{
	t_count		count;
	t_pivot		point;
	int			idx;

	count = (t_count){0, 0, 0, 0};
	if (check_sort_a(info, size))
		return ;
	if (size <= 4)
	{
		small_sort_a(info, size);
		return ;
	}
	point = get_pivot(info, size, 1);
	a_to_b_util(info, &count, point, size);
	idx = -1;
	while (++idx < count.ra)
		rrr(info);
	a_to_b(info, count.ra);
	b_to_a(info, count.rb);
	b_to_a(info, count.pb - count.rb);
}

void		b_to_a(t_info *info, int size)
{
	t_count		count;
	t_pivot		point;
	int			idx;

	count = (t_count){0, 0, 0, 0};
	if (check_sort_b(info, size))
	{
		while (size--)
			pa(info);
		return ;
	}
	if (size <= 3)
	{
		small_sort_b(info, size);
		return ;
	}
	point = get_pivot(info, size, 0);
	b_to_a_util(info, &count, point, size);
	a_to_b(info, count.pa - count.ra);
	idx = -1;
	while (++idx < count.ra)
		rrr(info);
	a_to_b(info, count.rb);
	b_to_a(info, count.ra);
}

void		push_swap(int argc, char *argv[])
{
	t_info	info;
	
	setnum(&info, argc, argv);
	if (!check_sort_a(&info, info.size))
	{
		if (info.a_top == 2)
			three_arg(&info);
		else if (info.a_top == 4)
			five_arg(&info);
		else
			a_to_b(&info, info.size);
	}
	free(info.a);
	free(info.b);
}
