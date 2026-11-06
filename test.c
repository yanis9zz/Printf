#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include "libft/libft.h"
int	putnbr_count(int n)
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
		count += putnbr_count(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int ft_putunsigned(unsigned int n)
{
    int count = 0;

    if (n >= 10)
        count += ft_putunsigned(n / 10);
    ft_putchar_fd(((n % 10) + '0'), 1);
	count++;
    return (count);
}
int	ft_puthex(uintptr_t n, char format)
{
	int count;
	char	*base;

	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	ft_putchar_fd(base[n % 16], 1);
	count++;
	return (count);
}

int	afficher(const	char *texte, ...)
{
	int   i;
	int		j;
	unsigned int u;
	unsigned int x;
	int   count;
	va_list	args;
	char	c;
	char	*str;
	int		nbr;
	void	*p;

	va_start(args, texte);
	i = 0;
	count = 0;
	while (texte[i])
	{
		if (texte[i] == '%' && texte[i + 1] == '%')
		{
 			write(1, "%", 1);
			i += 2;
			count++;
		}
		else if (texte[i] == '%' && texte[i + 1] == 'c')
		{
			c = va_arg(args, int);
 			write(1, &c, 1);
			i += 2;
			count++;
		}
		else if (texte[i] == '%' && texte[i + 1] == 's')
		{
			j = 0;
			str = va_arg(args, char *);
			while (str[j])
 				write(1, &str[j++], 1);
			i += 2;
			count += j;
		}
		else if (texte[i] == '%' && ((texte[i + 1] == 'd') || (texte[i + 1] == 'i')))
		{
			nbr = va_arg(args, int);
			count += putnbr_count(nbr);
			i+=2;
		}
		else if (texte[i] == '%' && texte[i + 1] == 'u')
		{
			u = va_arg(args, unsigned int);
			count += ft_putunsigned(u);
			i+=2;
		}
		else if (texte[i] == '%' && ((texte[i + 1] == 'x') || (texte[i + 1] == 'X')))
		{
			x = va_arg(args, unsigned int);
			count += ft_puthex(x, texte[i + 1]);
			i+= 2;
		}
		else if (texte[i] == '%' && texte[i + 1] == 'p')
		{
			p = va_arg(args, void *);
			if (p == NULL)
			{
				write(1, "(nil)", 5);
				count += 5;
				i += 2;
			}
			else
			{
				write(1, "0x", 2);
				count += 2;
				count += ft_puthex((uintptr_t)p, 'x');
				i+= 2;
			}
		}
		else
		{
			write(1, &texte[i], 1);
			i++;
			count++;
		}
		}
	va_end(args);
	return (count);
}

