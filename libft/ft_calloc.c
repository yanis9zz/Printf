/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/03 15:32:28 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n == 0 || size == 0)
		return (malloc(1));
	if (n > (size_t) - 1 / size)
		return (NULL);
	ptr = malloc(size * n);
	if (ptr != NULL)
		ft_bzero(ptr, n * size);
	return (ptr);
}

/*
int	main(void)
{
	int	*numbers;

	numbers = ft_calloc(3, sizeof(*numbers));
	if (!numbers)
		return (1);
	printf("%d %d %d\n",
		numbers[0], numbers[1], numbers[2]);
	free(numbers);
	return (0);
}
*/
