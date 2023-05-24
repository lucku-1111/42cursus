/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 01:36:29 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:30:01 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setbuf_d(long long arg, int bufsize, int len, t_spec spec)
{
	t_box box;

	if ((box.buf = malloc(sizeof(char) * bufsize)) == NULL)
		return (NULL);
	box.start = box.buf;
	ft_memset(box.buf, ' ', bufsize);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(box.buf, '0', bufsize);
	box.i = spec.precision;
	if (spec.minus)
	{
		ft_setsign_d(arg, &(box.buf), spec, box.start);
		while ((box.i)-- > len)
			*(box.buf++) = '0';
		ft_setnum_d(arg, box.buf + len - 1, spec);
	}
	else
	{
		ft_setnum_d(arg, box.buf + bufsize - 1, spec);
		box.buf = box.buf + bufsize - 1 - len;
		while ((box.i)-- > len)
			*(box.buf--) = '0';
		ft_setsign_d(arg, &(box.buf), spec, box.start);
	}
	return (box.start);
}

void	ft_setnum_d(long long num, char *tail, t_spec spec)
{
	if (spec.precision == 0 && num == 0)
		return ;
	if (num < 0)
		num = -1 * num;
	while (num >= 10)
	{
		*tail-- = num % 10 + '0';
		num /= 10;
	}
	*tail = num % 10 + '0';
}

void	ft_setsign_d(long long num, char **buf, t_spec spec, char *start)
{
	if (spec.zero && !spec.minus && spec.precision == -1)
		*buf = start;
	if (num < 0)
	{
		**buf = '-';
		*buf += 1;
	}
}
