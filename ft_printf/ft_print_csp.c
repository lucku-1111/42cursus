/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:20:51 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:31:36 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_spec spec, va_list ap)
{
	int		result;
	char	c;
	char	*buf;

	c = (char)va_arg(ap, int);
	if (spec.width < 1)
		spec.width = 1;
	if ((buf = (char *)malloc(sizeof(char) * (spec.width))) == NULL)
		return (-1);
	ft_memset(buf, ' ', spec.width);
	if (spec.minus)
		*buf = c;
	else
		*(buf + spec.width - 1) = c;
	result = write(1, buf, spec.width);
	free(buf);
	return (result);
}

int		ft_print_s(t_spec spec, va_list ap)
{
	int		len_buf;
	int		result;
	char	*str;
	char	*buf;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len_buf = ft_get_bufsize_s(&spec, str);
	if ((buf = malloc(sizeof(char) * len_buf)) == NULL)
		return (-1);
	ft_bufset_s(spec, len_buf, str, buf);
	result = write(1, buf, len_buf);
	free(buf);
	return (result);
}

int		ft_get_bufsize_s(t_spec *spec, char *str)
{
	int		len_str;
	int		len_buf;

	len_str = ft_strlen(str);
	if (spec->precision < 0 && spec->width < len_str)
		len_buf = len_str;
	else if (spec->precision < 0)
		len_buf = spec->width;
	else
	{
		if (len_str < spec->width)
			len_str = spec->width;
		if (spec->width >= spec->precision)
			len_buf = spec->width;
		else
		{
			if (spec->precision > len_str)
				len_buf = len_str;
			else
				len_buf = spec->precision;
		}
	}
	return (len_buf);
}

int		ft_print_p(t_spec spec, va_list ap)
{
	char	*addr;
	void	*p;
	int		result;

	if (spec.precision > 0)
		return (-1);
	p = (void *)va_arg(ap, void *);
	if ((addr = ft_getaddr_p(p, &spec)) == NULL)
		return (-1);
	result = write(1, addr, spec.width);
	free(addr);
	return (result);
}
