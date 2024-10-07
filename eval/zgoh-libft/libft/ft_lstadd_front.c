/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:03:53 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/11 09:26:35 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
//lst: address of pointer to the first node
//new: address of pointer to the new node (to be added in list)
//line 22: check whether is an empty list
//	>new node can be add directly if is empty list
//if not, link current node as new node's next
//	>then move *lst to point the new as the first node
