/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:41:13 by cerebus           #+#    #+#             */
/*   Updated: 2021/04/28 00:27:10 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move(t_list **new_lst, t_list **p)
{
	*new_lst = *new_lst;
	*p = (*p)->next;
}

static void	init(t_list **new_next, t_list **p, t_list *lst)
{
	*new_next = NULL;
	*p = lst;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new_lst;
	t_list	*new_next;

	init(&new_next, &p, lst);
	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(p->content));
	if (!new_lst)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	move(&new_lst, &p);
	while (p)
	{
		new_next->next = ft_lstnew(f(p->content));
		if (!new_next->next)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		move(&new_lst, &p);
	}
	return (new_lst);
}
