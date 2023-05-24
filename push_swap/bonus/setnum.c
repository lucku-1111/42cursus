/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:26:14 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 14:32:39 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		num_size(const char *str, char c)
{
	int		size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != c)
		{
			size++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	if (!size)
		go_error();
	return (size);
}

static void		info_init(t_info *info, int size)
{
	if ((info->a = (int *)malloc(sizeof(int) * size)) == NULL)
		exit(1);
	if ((info->b = (int *)malloc(sizeof(int) * size)) == NULL)
	{
		free(info->a);
		exit(1);
	}
	info->a_top = -1;
	info->b_top = -1;
	info->size = size;
}

static int		check_duplicate(int *arr, int size, int num)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (arr[idx] == num)
			return (0);
		idx++;
	}
	return (1);
}

static void		swap_stack(t_info *info)
{
	int		top;
	int		bottom;
	int		tmp;

	top = 0;
	bottom = info->a_top;
	while (top < bottom)
	{
		tmp = info->a[top];
		info->a[top] = info->a[bottom];
		info->a[bottom] = tmp;
		top++;
		bottom--;
	}
}

void			setnum(t_info *info, int argc, char *argv[])
{
	int		size;
	int		idx;
	int		tmp_idx;
	char	**tmp;

	size = 0;
	idx = 1;
	while (idx < argc)
		size += num_size(argv[idx++], ' ');
	info_init(info, size);
	idx = 1;
	while (idx < argc)
	{
		tmp_idx = 0;
		tmp = ft_split(argv[idx++], ' ');
		while (tmp[tmp_idx])
		{
			info->a_top += 1;
			if (!ft_atoi(tmp[tmp_idx++], &info->a[info->a_top]) ||
				!check_duplicate(info->a, info->a_top, info->a[info->a_top]))
				go_error();
		}
		free_strs(tmp, tmp_idx);
	}
	swap_stack(info);
}
