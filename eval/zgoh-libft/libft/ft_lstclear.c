/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:40:22 by zgoh              #+#    #+#             */
/*   Updated: 2024/03/17 19:57:23 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		ft_lstdelone(temp, del);
		temp = next;
	}
	*lst = NULL;
}
/*
line 40: now temp also pointing to start of list
line 45: delete current node's content that stored inside pointer content first
line 46: after delete the content, current node can be free
line 47: pointer next is holding the address of next node,
		 now assigning the value to temp pointer
line 49: indicate that the list pointing by *lst is cleared,
	 important to have it to prevent access a corrupted / freed data structure
*/
/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		if (temp->content != NULL)
			del(temp-> content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
*/
