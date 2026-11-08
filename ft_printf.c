/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:52:51 by ubuntu            #+#    #+#             */
/*   Updated: 2026/11/08 10:43:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include <stdarg.h>

static int	ft_pointers(void *p)
{
	int	count;

	count = 0;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		count += 5;
	}
	else
	{
		write(1, "0x", 2);
		count += 2;
		count += ft_puthex((uintptr_t)p, 'x');
	}
	return (count);
}

static int	ft_dispatch(char conversion, va_list *args)
{
	if (conversion == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	if (conversion == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	if (conversion == '%')
		return (ft_putchar_count('%'));
	if (conversion == 'd' || conversion == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (conversion == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (conversion == 'x' || conversion == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), conversion));
	if (conversion == 'p')
		return (ft_pointers(va_arg(*args, void *)));
	return (0);
}

static int	ft_parse_format(const char *format, va_list *args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_dispatch(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_putchar_count(format[i]);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parse_format(format, &args);
	va_end(args);
	return (count);
}
