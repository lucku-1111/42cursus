/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:28:10 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/12 02:05:51 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char c, t_spec spec, va_list ap)
{
	if (c == 'c')
		return (ft_print_c(spec, ap));
	else if (c == 's')
		return (ft_print_s(spec, ap));
	else if (c == 'p')
		return (ft_print_p(spec, ap));
	else if (c == 'd')
		return (ft_print_d(spec, ap));
	else if (c == 'i')
		return (ft_print_d(spec, ap));
	else if (c == 'u')
		return (ft_print_u(spec, ap));
	else if (c == 'x')
		return (ft_print_x(spec, ap));
	else if (c == 'X')
		return (ft_print_upper_x(spec, ap));
	else if (c == '%')
		return (ft_print_percent(spec));
	return (0);
}

static char	*pars_format(const char *str)
{
	while (*str)
	{
		if (*str == 'c' ||
		*str == 's' ||
		*str == 'p' ||
		*str == 'd' ||
		*str == 'i' ||
		*str == 'u' ||
		*str == 'x' ||
		*str == 'X' ||
		*str == '%')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

static int	ft_print(const char *str, va_list ap)
{
	t_spec	spec;
	char	*format;

	if ((format = pars_format(str)) == NULL)
		return (-1);
	spec = pars_spec(str, format - str, ap, *format);
	if (spec.errno != 0)
		return (-1);
	return (ft_print_format(*format, spec, ap));
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	int		length;
	char	*find;

	if (format == NULL)
		return (-1);
	result = 0;
	va_start(ap, format);
	while ((find = ft_strchr(format, '%')))
	{
		result += write(1, format, find - format);
		if ((length = ft_print(find + 1, ap)) < 0)
			return (-1);
		result += length;
		format = pars_format(find + 1) + 1;
	}
	result += write(1, format, ft_strlen(format));
	va_end(ap);
	return (result);
}
