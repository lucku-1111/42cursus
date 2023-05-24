/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:19:58 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:29:38 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_u(t_spec spec, va_list ap)
{
	unsigned int	arg;
	char			*buf;
	int				result;
	int				bufsize;
	int				len;

	arg = (unsigned int)va_arg(ap, unsigned int);
	len = ft_get_numsize_d(arg, spec);
	if (spec.width <= 0 && spec.precision == 0 && arg == 0)
		return (0);
	bufsize = ft_get_bufsize_d(spec, len, 0);
	if ((buf = ft_setbuf_d(arg, bufsize, len, spec)) == NULL)
		return (-1);
	result = write(1, buf, bufsize);
	free(buf);
	return (result);
}
