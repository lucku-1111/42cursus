/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 02:05:45 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:32:00 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setbuf_x(long long arg, int bufsize, int isupper, t_spec spec)
{
	t_box	box;

	if ((box.buf = malloc(sizeof(char) * bufsize)) == NULL)
		return (NULL);
	box.size = ft_get_numsize_x(arg, spec);
	box.start = box.buf;
	ft_memset(box.buf, ' ', bufsize);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(box.buf, '0', bufsize);
	box.i = spec.precision;
	if (spec.minus)
	{
		while ((box.i)-- > box.size.len)
			*(box.buf++) = '0';
		ft_setnum_x(arg, box.buf + box.size.len - 1, isupper, spec);
	}
	else
	{
		ft_setnum_x(arg, box.buf + bufsize - 1, isupper, spec);
		box.buf = box.buf + bufsize - 1 - box.size.len;
		while ((box.i)-- > box.size.len)
			*(box.buf--) = '0';
	}
	return (box.start);
}

void	ft_setnum_x(long long num, char *tail, int isupper, t_spec spec)
{
	if (spec.precision == 0 && num == 0)
		return ;
	while (num >= 16)
	{
		if (!isupper)
			*tail-- = "0123456789abcdef"[num % 16];
		else
			*tail-- = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	if (!isupper)
		*tail = "0123456789abcdef"[num % 16];
	else
		*tail = "0123456789ABCDEF"[num % 16];
}
