/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:11:07 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 14:21:33 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = info->a_top;
	if (idx != -1)
	{
		tmp = info->a[info->a_top];
		while (idx > 0)
		{
			info->a[idx] = info->a[idx - 1];
			idx--;
		}
		info->a[0] = tmp;
	}
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = info->b_top;
	if (idx != -1)
	{
		tmp = info->b[info->b_top];
		while (idx > 0)
		{
			info->b[idx] = info->b[idx - 1];
			idx--;
		}
		info->b[0] = tmp;
	}
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	ra(info, 0);
	rb(info, 0);
	write(1, "rr\n", 3);
}
