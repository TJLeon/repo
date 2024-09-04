/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:46:51 by leotan            #+#    #+#             */
/*   Updated: 2024/09/04 09:36:49 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_stack *a)
{
	while (a->status != 2 && a->data < a->next->data)
		a = a->next;
	if (a->status == 2 && a->data > a->next->data)
		return (1);
	return (0);
}

t_stack	*ft_list_dupe(t_stack *o)
{
	t_stack	*c;
	t_stack	*t;

	c = NULL;
	while (o->status != 2)
	{
		t = malloc(sizeof(t_stack));
		t->status = o->status;
		t->data = o->data;
		t->prev = c;
		if (c != NULL)
			c->next = t;
		c = t;
		o = o->next;
	}
	t = malloc(sizeof(t_stack));
	t->status = o->status;
	t->data = o->data;
	t->prev = c;
	c->next = t;
	while (c->status != 0)
		c = c->prev;
	t->next = c;
	c->prev = t;
	return (c);
}
