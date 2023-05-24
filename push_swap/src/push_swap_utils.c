/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 13:59:13 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/06 16:01:16 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_arg(t_info *info)
{
	if (info->a[2] > info->a[1])
		sa(info, 1);
	if (info->a[0] < info->a[1])
	{
		rra(info, 1);
		if (info->a[1] < info->a[2])
			sa(info, 1);
	}
}

void	four_arg(t_info *info)
{
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pb(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pb(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1]
		&& info->b[info->b_top] < info->b[info->b_top - 1])
		ss(info);
	else if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	else if (info->b[info->b_top] < info->b[info->b_top - 1])
		sb(info, 1);
	pa(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pa(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
}

void	five_arg(t_info *info)
{
	int *arr;
	int idx;

	idx = -1;
	arr = copy_arr(info, 5, 1);
	ft_sort(arr, 5);
	while (++idx < 5)
	{
		if (arr[1] >= info->a[info->a_top])
			pb(info);
		else
			ra(info, 1);
	}
	three_arg(info);
	if (info->b[0] > info->b[1])
		sb(info, 1);
	pa(info);
	pa(info);
	free(arr);
}

void	a_to_b_util(t_info *info, t_count *count, t_pivot point, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (info->a[info->a_top] >= point.p1)
		{
			ra(info, 1);
			count->ra += 1;
		}
		else
		{
			pb(info);
			count->pb += 1;
			if (info->b[info->b_top] >= point.p2)
			{
				rb(info, 1);
				count->rb += 1;
			}
		}
		idx++;
	}
}

void	b_to_a_util(t_info *info, t_count *count, t_pivot point, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (info->b[info->b_top] <= point.p2)
		{
			rb(info, 1);
			count->rb += 1;
		}
		else
		{
			pa(info);
			count->pa += 1;
			if (info->a[info->a_top] <= point.p1)
			{
				ra(info, 1);
				count->ra += 1;
			}
		}
		idx++;
	}
}
