/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 15:30:20 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxt;
	}
}

/*
static void	demo_del(void *content)
{
	// Les textes sont empruntes : ne pas liberer les litteraux.
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*list;
	t_list	*second;

	list = ft_lstnew("un");
	if (!list)
		return (1);
	second = ft_lstnew("deux");
	if (!second)
	{
		ft_lstclear(&list, demo_del);
		return (1);
	}
	list->next = second;
	ft_lstclear(&list, demo_del);
	printf("%d\n", list == NULL);
	return (0);
}
*/
