/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:22:44 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/01 23:25:15 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst ||!del)
		return ;
	del(lst->content);
	free(lst);
}
//the sequence: delete node's content then free the node
//can prevent memory leak and ensure proper memory management

//Let's say if del(lst->content) deallocate the memory
//	 for lst->content and set it as NULL.
//If free the node first, the reference to lst->content will lost,
//	 then you can't pass it to del. 
//This could lead to a memory leak because unable to free the content.
