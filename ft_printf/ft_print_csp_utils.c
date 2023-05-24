/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:22:58 by seoklee           #+#    #+#             */
/*   Updated: 2021/06/15 15:30:08 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bufset_s(t_spec spec, int len_buf, char *str, char *buf)
{
	int	len_output;

	len_output = ft_strlen(str);
	if (spec.zero && !spec.minus && spec.precision == -1)
		ft_memset(buf, '0', len_buf);
	else
		ft_memset(buf, ' ', len_buf);
	if (spec.precision > -1 && spec.precision < len_output)
		len_output = spec.precision;
	if (spec.minus)
		ft_memcpy(buf, str, len_output);
	else
		ft_memcpy(buf + len_buf - len_output, str, len_output);
}

char	*ft_getaddr_p(void *p, t_spec *spec)
{
	long long	addr;
	int			size;
	char		*result;
	int			i;

	size = ft_getaddr_size_p((long long)p, *spec);
	if (spec->width < size)
		spec->width = size;
	if ((result = malloc(sizeof(char) * (spec->width))) == NULL)
		return (NULL);
	ft_memset(result, ' ', spec->width);
	addr = (long long)p;
	if (spec->minus)
		i = size - 1;
	else
		i = spec->width - 1;
	while (size-- - 2)
	{
		*(result + i--) = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	*(result + i--) = 'x';
	*(result + i) = '0';
	return (result);
}

int		ft_getaddr_size_p(long long addr, t_spec spec)
{
	int	result;

	if (spec.precision == 0 && addr == 0)
		return (2);
	result = 3;
	while (addr >= 16)
	{
		addr /= 16;
		result += 1;
	}
	return (result);
}
