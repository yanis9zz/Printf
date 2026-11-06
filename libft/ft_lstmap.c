/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 16:32:22 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
static void	*demo_duplicate(void *content)
{
	return (ft_strdup((char *)content));
}
int	main(void)
{
	t_list	first;
	t_list	second;
	t_list	*mapped;
	t_list	*cursor;

	second.content = "deux";
	second.next = NULL;
	first.content = "un";
	first.next = &second;
	mapped = ft_lstmap(&first, demo_duplicate, free);
	if (!mapped)
		return (1);
	cursor = mapped;
	while (cursor)
	{
		if (cursor->content)
			printf("%s\n", (char *)cursor->content);
		else
			printf("NULL\n");
		cursor = cursor->next;
	}
	ft_lstclear(&mapped, free);
	return (0);
}
*/
