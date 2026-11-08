/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:33:14 by ubuntu            #+#    #+#             */
/*   Updated: 2026/11/08 18:23:09 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include <stdint.h>
# include <stddef.h>

int	ft_putnbr_count(int n);
int	ft_putstr_count(const char *str);
int	ft_write_all(const char *str, size_t n);
int	ft_putunsigned(unsigned int n);

#endif
