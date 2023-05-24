/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:11:07 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 15:59:22 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_info *info)
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
}

void	rb(t_info *info)
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
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}
