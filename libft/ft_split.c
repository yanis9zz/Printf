/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/02 13:59:49 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_tab(char **res, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(res[j++]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	k = 0;
	while (s[k] == c && s[k] != '\0')
		k++;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[k])
	{
		j = 0;
		res[i] = malloc(sizeof(char) * (len_word(s + k, c) + 1));
		if (!res[i])
			return (free_tab(res, i), NULL);
		while (s[k] && s[k] != c)
			res[i][j++] = s[k++];
		while (s[k] && s[k] == c)
			k++;
		res[i++][j] = '\0';
	}
	return (res[i] = NULL, res);
}

/*
int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("salut les amis", ' ');
	if (!words)
		return (1);
	i = 0;
	while (words[i])
	{
		printf("%s\n", words[i]);
		free(words[i++]);
	}
	free(words);
	return (0);
}
*/
