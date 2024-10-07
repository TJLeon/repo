/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:46:32 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/08 16:57:59 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return value:
//	>new list that successful apply f()
//	>NULL if allocation failed

//what is happening?
//1. Iterates the list ’lst’ and apply f() on the content of each node. 
//2. Creates a new list resulting of the successive applications of f() 
//3. del() is used to delete the content of a node if fail to apply f().

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;

	if (!lst || !f || !del)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			del(new->content);
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}

//variable explaination:
//	>new_lst:   is the new list will contain all nodes 
//				where their content is lst's content that have applied f()
//	>new: new node, that will hold content have been through f()
//line 32: indicate that new_lst still an empty list at that stage
//line 35: store the content have been through f() into new (the node)
//	>ft_lstnew will return a new node with content
//	>the content been passing is not the original content,
//	 but the content have passed to f()
//line 36: check whether the assign is success
//	>if pointer new holding NULL, mean is failed
//	>so content of new will be passed to del(), for clearing content
//line 38: after successful create a new node
//	>the nodes will be linked together by using ft_lstadd_back
//	>ft_lstadd_back received **lst and *new
//	>so we passing address of *new_lst, so the **lst will point to *new_list
