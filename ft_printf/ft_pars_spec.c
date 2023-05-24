/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:14:36 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/12 02:13:18 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec			pars_spec(const char *str, int length, va_list ap, char format)
{
	t_spec spec;

	init_spec(&spec);
	if (length == 0)
		return (spec);
	while (pars_flag(*str, &spec))
		++str;
	pars_width(&str, &spec, ap);
	pars_precision(&str, &spec, ap);
	if (*str != format)
		spec.errno = -1;
	return (spec);
}

void			init_spec(t_spec *spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->width = -1;
	spec->precision = -1;
	spec->errno = 0;
}

int				pars_flag(int c, t_spec *spec)
{
	if (c == '-')
	{
		spec->minus = 1;
		return (1);
	}
	else if (c == '0')
	{
		spec->zero = 1;
		return (1);
	}
	return (0);
}

void			pars_width(const char **str, t_spec *spec, va_list ap)
{
	char	c;

	c = **str;
	if (c == '*')
	{
		spec->width = va_arg(ap, int);
		if (spec->width < 0)
		{
			spec->minus = 1;
			spec->width *= (-1);
		}
		(*str)++;
	}
	else if (ft_isdigit(c))
	{
		spec->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
}

void			pars_precision(const char **str, t_spec *spec, va_list ap)
{
	char	c;

	if (**str != '.')
		return ;
	c = *(++(*str));
	if (c == '*')
	{
		spec->precision = va_arg(ap, int);
		if (spec->precision < 0)
			spec->precision = -1;
		++(*str);
	}
	else if (ft_isdigit(c))
	{
		spec->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			++(*str);
	}
	else
		spec->precision = 0;
}
