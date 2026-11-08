/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:33:14 by ubuntu            #+#    #+#             */
/*   Updated: 2026/11/08 10:37:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include <stdint.h>

int	ft_putnbr_count(int n);
int	ft_putstr_count(const char *str);
int	ft_putchar_count(char c);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(uintptr_t n, char format);

#endif
