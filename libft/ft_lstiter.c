/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutakh <yboutakh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:59:49 by yboutakh          #+#    #+#             */
/*   Updated: 2026/11/04 15:35:03 by yboutakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
static void	demo_increment(void *content)
{
	(*(int *)content)++;
}

int	main(void)
{
	int		a;
	int		b;
	t_list	first;
	t_list	second;

	a = 1;
	b = 2;
	second.content = &b;
	second.next = NULL;
	first.content = &a;
	first.next = &second;
	ft_lstiter(&first, demo_increment);
	printf("%d %d\n", a, b);
	return (0);
}
*/
