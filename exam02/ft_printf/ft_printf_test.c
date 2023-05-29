/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 02:13:55 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/30 02:38:20 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	is_string(char *str)
{
	int	i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	hex_num(unsigned int num, int base)
{
	int		i = 0;
	int		count = 0;
	char	dec[] = "0123456789";
	char	hex[] = "0123456789abcdef";

	if (num / base != 0)
		count += hex_num(num / base, base);
	i = num % base;
	if (base == 10)
		count += ft_putchar(1, &dec[i], 1);
	if (base == 16)
		count += ft_putchar(1, &hex[i], 1);
	return (count);
}

int	dec_num(int num)
{
	int	count = 0;

	if (num < 0)
	{
		count += ft_putchar("-");
		num = num * (-1);
	}
	count += hex_num(num, 10);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i = 0;
	int		count = 0;
	va_list	arg;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += is_string(va_arg(arg, char *));
			if (format[i] == 'd')
				count += dec_num(va_arg(arg, int));
			if (format[i] == 'x')
				count += hex_num(va_arg(arg, unsigned int), 16);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
