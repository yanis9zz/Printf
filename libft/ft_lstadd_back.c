/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 16:28:31 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	return ;
}

/*
int	main(void)
{
	t_list	first;
	t_list	second;
	t_list	*list;

	first.content = "un";
	first.next = NULL;
	second.content = "deux";
	second.next = NULL;
	list = &first;
	ft_lstadd_back(&list, &second);
	printf("%d\n", first.next == &second);
	printf("%u\n", ft_lstsize(list));
	return (0);
}
*/
