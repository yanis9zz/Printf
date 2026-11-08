/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:52:51 by ubuntu            #+#    #+#             */
/*   Updated: 2026/11/08 18:55:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include <stdarg.h>

static int	ft_puthex(uintptr_t n, char format)
{
	int		count;
	char	*base;
	int		written;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		written = ft_puthex(n / 16, format);
		if (written < 0)
			return (-1);
		count += written;
	}
	written = ft_write_all(&base[n % 16], 1);
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}

static int	ft_pointers(void *p)
{
	int	count;
	int	written;

	count = 0;
	if (p == NULL)
	{
		written = ft_write_all("(nil)", 5);
		if (written < 0)
			return (-1);
		count += written;
	}
	else
	{
		written = ft_write_all("0x", 2);
		if (written < 0)
			return (-1);
		count += written;
		written = ft_puthex((uintptr_t)p, 'x');
		if (written < 0)
			return (-1);
		count += written;
	}
	return (count);
}

static int	ft_dispatch(char conversion, va_list *args)
{
	char	c;

	if (conversion == 's')
		return (ft_putstr_count(va_arg(*args, char *)));
	if (conversion == 'c')
	{
		c = va_arg(*args, int);
		return (ft_write_all(&c, 1));
	}
	if (conversion == '%')
		return (ft_write_all("%", 1));
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
	int	written;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			written = ft_dispatch(format[i + 1], args);
			if (written < 0)
				return (-1);
			count += written;
			i += 2;
		}
		else
		{
			written = ft_write_all(&format[i++], 1);
			if (written < 0)
				return (-1);
			count += written;
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
