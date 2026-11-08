/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:32:30 by ubuntu            #+#    #+#             */
/*   Updated: 2026/11/08 10:36:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_putnbr_count(int n)
{
	long	nb;
	char	c;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr_count(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr_count(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar_count(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putunsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	c = ((n % 10) + '0');
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_puthex(uintptr_t n, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	write(1, &base[n % 16], 1);
	count++;
	return (count);
}
