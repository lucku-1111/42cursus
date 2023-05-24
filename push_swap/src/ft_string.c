/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:38:51 by seoklee           #+#    #+#             */
/*   Updated: 2021/07/05 14:21:27 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_atoi(char *str, int *result)
{
	long	tmp;
	int		positive;

	tmp = 0;
	positive = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		tmp *= 10;
		tmp += (*str - '0') * positive;
		str++;
	}
	if (*str != '\0' || tmp > 2147483647 || tmp < -2147483648)
		return (0);
	*result = tmp;
	return (1);
}

int			ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t idx;

	if (!dest || !src)
		return (0);
	idx = 0;
	if (size != 0)
	{
		while (idx < size - 1 && *src)
		{
			*dest = *src;
			dest++;
			src++;
			idx++;
		}
		*dest = '\0';
	}
	while (*src++)
		idx++;
	return (idx);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*save;

	save = (unsigned char *)b;
	while (len--)
	{
		*save++ = (unsigned char)c;
	}
	return (b);
}

void		ft_putstr_fd(char *s, int fd)
{
	size_t	size;
	int		idx;

	size = 0;
	idx = 0;
	if (!s)
		return ;
	while (s[idx++])
		size++;
	write(fd, s, size);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (!(c = malloc(size * count)))
		return (NULL);
	ft_memset(c, 0, size * count);
	return (c);
}
