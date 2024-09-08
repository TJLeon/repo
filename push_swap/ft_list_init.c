/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:31:42 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 17:35:33 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_list_init_head(t_stack *new)
{
	new->next = NULL;
	new->prev = NULL;
	new->status = 0;
	return (new);
}

static t_stack	*ft_list_init_tail(t_stack *ptr, t_stack *new)
{
	new->next = ptr;
	new->prev = ptr;
	new->status = 2;
	ptr->next = new;
	ptr->prev = new;
	return (ptr);
}

static t_stack	*ft_list_new_tail(t_stack *ptr, t_stack *new)
{
	new->prev = ptr;
	new->next = ptr->next;
	new->status = 2;
	new->next->prev = new;
	ptr->next = new;
	ptr->status = 1;
	return (new->next);
}

t_stack	*ft_list_add_num(t_stack *ptr, long num, char **str)
{
	t_stack	*new;

	if (str == NULL)
		ft_kill_switch(NULL, ptr);
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_kill_switch((void **)str, ptr);
	new->data = num;
	while (ptr != NULL && ptr->next != NULL && ptr->status != 2)
		ptr = ptr->next;
	if (ptr == NULL)
		return (ft_list_init_head(new));
	if (ptr->next == NULL)
		return (ft_list_init_tail(ptr, new));
	return (ft_list_new_tail(ptr, new));
}
