/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:26:45 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/09 18:26:47 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_write_all(const char *str, size_t len)
{
	size_t	i;
	ssize_t	j;

	i = 0;
	while (i < len)
	{
		j = write(1, str + i, len - i);
		if (j <= 0)
			return (-1);
		i += j;
	}
	return ((int)i);
}

static int	ft_putnbr_helper(long nb)
{
	int		written;
	int		count;
	char	c;

	count = 0;
	if (nb >= 10)
	{
		written = ft_putnbr_helper(nb / 10);
		if (written < 0)
			return (-1);
		count += written;
	}
	c = (nb % 10) + '0';
	written = ft_write_all(&c, 1);
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}

int	ft_putnbr_count(int n)
{
	long	nb;
	int		count;
	int		written;

	nb = (long)n;
	count = 0;
	if (nb == 0)
	{
		written = ft_write_all("0", 1);
		if (written < 0)
			return (-1);
		return (1);
	}
	else if (nb < 0)
	{
		written = ft_write_all("-", 1);
		if (written < 0)
			return (-1);
		count += written;
		nb = -nb;
	}
	written = ft_putnbr_helper(nb);
	if (written < 0)
		return (-1);
	return (count + written);
}

int	ft_putstr_count(const char *str)
{
	size_t	len;

	if (!str)
		return (ft_write_all("(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (ft_write_all(str, len));
}

int	ft_putunsigned(unsigned int n)
{
	int		count;
	int		written;
	char	c;

	count = 0;
	if (n >= 10)
	{
		written = ft_putunsigned(n / 10);
		if (written < 0)
			return (-1);
		count += written;
	}
	c = ((n % 10) + '0');
	written = ft_write_all(&c, 1);
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}
