/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:07:29 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/23 00:07:29 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static int	check_format(const char *format, va_list args)
{
	int	len_format;

	len_format = 0;
	if (*format == 'c')
		len_format += ft_put_char(va_arg(args, int));
	else if (*format == 's')
		len_format += ft_put_string(va_arg(args, char *));
	else if (*format == 'p')
		len_format += ft_put_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		len_format += ft_put_integer(va_arg(args, int));
	else if (*format == 'u')
		len_format += ft_put_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		len_format += ft_put_hexadecimal(va_arg(args, unsigned int), 'x');
	else if (*format == 'X')
		len_format += ft_put_hexadecimal(va_arg(args, unsigned int), 'X');
	return (len_format);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_format;
	va_list	args;

	i = 0;
	len_format = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			len_format += ft_put_char('%');
			i++;
		}
		else if (format[i] == '%' && ft_strchr("cspdiuxX", format[i + 1]))
		{
			len_format += check_format(&format[i + 1], args);
			i++;
		}
		else
			len_format += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (len_format);
}
