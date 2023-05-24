/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:26:11 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:31:06 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_d(t_spec spec, va_list ap)
{
	int		arg;
	int		sign;
	int		len;
	int		bufsize;
	char	*buf;

	arg = (int)va_arg(ap, int);
	len = ft_get_numsize_d(arg, spec);
	sign = 0;
	if (arg < 0)
		sign = 1;
	if (spec.width <= 0 && spec.precision == 0 && arg == 0)
		return (0);
	bufsize = ft_get_bufsize_d(spec, len, sign);
	if ((buf = ft_setbuf_d(arg, bufsize, len, spec)) == NULL)
		return (-1);
	len = write(1, buf, bufsize);
	free(buf);
	return (len);
}

int		ft_get_numsize_d(long long num, t_spec spec)
{
	int			result;
	long long	copy;

	if (num == 0 && spec.precision == 0)
		return (0);
	result = 1;
	if (num < 0)
		copy = (-1) * num;
	else
		copy = num;
	while (copy > 9)
	{
		copy /= 10;
		result++;
	}
	return (result);
}

int		ft_get_bufsize_d(t_spec spec, int len, int sign)
{
	int	bufsize;

	if (spec.width == -1 && spec.precision == -1)
		bufsize = len + sign;
	else if (spec.width > spec.precision)
	{
		if (len + sign < spec.width)
			bufsize = spec.width;
		else
			bufsize = len + sign;
	}
	else
	{
		if (len < spec.precision)
			bufsize = spec.precision + sign;
		else
			bufsize = len + sign;
	}
	return (bufsize);
}
