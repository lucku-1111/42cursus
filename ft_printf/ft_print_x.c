/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:26:59 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/12 02:13:00 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_x(t_spec spec, va_list ap)
{
	unsigned int	arg;
	char			*buf;
	t_size			size;
	int				bufsize;

	arg = (unsigned int)va_arg(ap, unsigned int);
	size = ft_get_numsize_x(arg, spec);
	if (spec.width <= 0 && spec.precision == 0 && arg == 0)
		return (0);
	bufsize = ft_get_bufsize_x(spec, size.len);
	if ((buf = ft_setbuf_x(arg, bufsize, 0, spec)) == NULL)
		return (-1);
	size.len = write(1, buf, bufsize);
	free(buf);
	return (size.len);
}

int		ft_print_upper_x(t_spec spec, va_list ap)
{
	unsigned int	arg;
	char			*buf;
	t_size			size;
	int				bufsize;

	arg = (unsigned int)va_arg(ap, unsigned int);
	size = ft_get_numsize_x(arg, spec);
	if (spec.width <= 0 && spec.precision == 0 && arg == 0)
		return (0);
	bufsize = ft_get_bufsize_x(spec, size.len);
	if ((buf = ft_setbuf_x(arg, bufsize, 1, spec)) == NULL)
		return (-1);
	size.len = write(1, buf, bufsize);
	free(buf);
	return (size.len);
}

t_size	ft_get_numsize_x(long long num, t_spec spec)
{
	t_size		result;
	long long	copy;

	result.is_zero_num = 0;
	result.is_zero_prec = 0;
	result.len = 1;
	if (num == 0)
		result.is_zero_num = 1;
	if (spec.precision == 0)
		result.is_zero_prec = 1;
	if (result.is_zero_num && result.is_zero_prec)
		return (result);
	if (num < 0)
		copy = (-1) * num;
	else
		copy = num;
	while (copy >= 16)
	{
		copy /= 16;
		result.len += 1;
	}
	return (result);
}

int		ft_get_bufsize_x(t_spec spec, int len)
{
	int		bufsize;

	if (spec.width == -1 && spec.precision == -1)
		bufsize = len;
	else if (spec.width > spec.precision)
	{
		if (len < spec.width)
			bufsize = spec.width;
		else
			bufsize = len;
	}
	else
	{
		if (len < spec.precision)
			bufsize = spec.precision;
		else
			bufsize = len;
	}
	return (bufsize);
}
