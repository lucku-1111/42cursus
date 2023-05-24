/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:54:39 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:29:23 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_percent(t_spec spec)
{
	char	*buf;
	int		result;

	if (spec.width <= 1)
		return (write(1, "%", 1));
	if ((buf = malloc(sizeof(char) * spec.width)) == NULL)
		return (-1);
	if (spec.zero && !spec.minus)
		ft_memset(buf, '0', spec.width);
	else
		ft_memset(buf, ' ', spec.width);
	if (spec.minus)
		*buf = '%';
	else
		*(buf + spec.width - 1) = '%';
	result = write(1, buf, spec.width);
	free(buf);
	return (result);
}
