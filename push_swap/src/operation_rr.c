/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:11:28 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 14:21:34 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->a[0];
	while (idx < info->a_top)
	{
		info->a[idx] = info->a[idx + 1];
		idx++;
	}
	info->a[info->a_top] = tmp;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->b[0];
	while (idx < info->b_top)
	{
		info->b[idx] = info->b[idx + 1];
		idx++;
	}
	info->b[info->b_top] = tmp;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	rra(info, 0);
	rrb(info, 0);
	write(1, "rrr\n", 4);
}
