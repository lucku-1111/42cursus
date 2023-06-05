/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:04:34 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 11:24:47 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int is_string(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return(i);
}	

int hex_num(unsigned int num, int base)
{
	int i = 0;
	int count = 0;
	char dec[] = "0123456789";
	char hex[] = "0123456789abcdef";

	if (num / base != 0)
		count += hex_num(num / base, base);
	i = num % base;
	if (base == 10)
		count += write(1, &dec[i], 1);
	if (base == 16)
		count += write(1, &hex[i], 1);
	return(count);
}

int ConvPush_num(int num)
{
	int count = 0;

	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	count += hex_num(num, 10);
	return (count);
}

int ft_printf(const char *format, ...)
{
	int	i = 0;
	int	count = 0;
	va_list args;
	
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += is_string(va_arg(args, char *));
			if (format[i] == 'd')
				count += ConvPush_num(va_arg(args, int));
			if (format[i] == 'x')
				count += hex_num(va_arg(args, unsigned int), 16);
		}
		else 
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
