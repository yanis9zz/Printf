/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 14:50:55 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	t_list			*cursor;
	unsigned int	i;

	cursor = lst;
	i = 0;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	first;
	t_list	second;

	second.content = "deux";
	second.next = NULL;
	first.content = "un";
	first.next = &second;
	printf("%u\n", ft_lstsize(&first));
	printf("%u\n", ft_lstsize(NULL));
	return (0);
}
*/
