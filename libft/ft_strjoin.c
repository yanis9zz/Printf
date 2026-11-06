/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/03 16:06:41 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	d = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s1, s1_len);
	ft_memcpy(d + s1_len, s2, s2_len + 1);
	return (d);
}

/*
int	main(void)
{
	char	*result;

	result = ft_strjoin("bon", "jour");
	if (!result)
		return (1);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
