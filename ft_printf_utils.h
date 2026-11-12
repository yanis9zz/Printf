/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:27:05 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/09 18:27:07 by yboutakh         ###   ########.fr       */
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
