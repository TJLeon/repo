/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:03:15 by mhamdan           #+#    #+#             */
/*   Updated: 2023/10/25 23:57:38 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*f_next;

	if (!lst || !f || !del)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		f_next = ft_lstnew(f(lst->content));
		if (!f_next)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, f_next);
		lst = lst->next;
	}
	return (new_node);
}
