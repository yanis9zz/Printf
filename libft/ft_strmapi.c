/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 06:58:54 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	d = malloc(sizeof(char) * (s_len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = f((unsigned int)i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
static char	demo_upper(unsigned int i, char c)
{
	(void)i;
	return ((char)ft_toupper((unsigned char)c));
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("salut", demo_upper);
	if (!result)
		return (1);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
