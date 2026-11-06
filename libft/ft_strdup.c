/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/03 15:43:23 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s);
	d = malloc (sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len + 1);
	return (d);
}

/*
int	main(void)
{
	char	*copy;

	copy = ft_strdup("bonjour");
	if (!copy)
		return (1);
	printf("%s\n", copy);
	free(copy);
	return (0);
}
*/
