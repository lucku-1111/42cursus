/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:08:08 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/27 16:04:06 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int		count;

	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int		count;
	char	*str;
	long	num;

	num = n;
	count = count_digit(num);
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		if (!(str = malloc(sizeof(char) * (++count + 1))))
			return (NULL);
		str[0] = '-';
		num *= -1;
	}
	else if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count--] = '\0';
	while (num)
	{
		str[count--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
