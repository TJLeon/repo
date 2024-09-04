/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:31:42 by leotan            #+#    #+#             */
/*   Updated: 2024/09/03 10:43:58 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_list_init_head(t_stack *new)
{
	new->next = NULL;
	new->prev = NULL;
	new->status = 0;
	return (new);
}

t_stack	*ft_list_init_tail(t_stack *p, t_stack *new)
{
	new->next = p;
	new->prev = p;
	new->status = 2;
	p->next = new;
	p->prev = new;
	return (p);
}

t_stack	*ft_list_add_tail(t_stack *p, t_stack *new)
{
	new->prev = p;
	new->next = p->next;
	new->status = 2;
	new->next->prev = new;
	p->next = new;
	p->status = 1;
	return (new->next);
}

t_stack	*ft_list_add_num(t_stack *p, long long n, char **s)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
	{
		ft_free_2d_arr(s);
		ft_free_list(&p);
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new->data = n;
	while (p != NULL && p->next != NULL && p->status != 2)
		p = p->next;
	if (p == NULL)
		return (ft_list_init_head(new));
	if (p->next == NULL)
		return (ft_list_init_tail(p, new));
	return (ft_list_add_tail(p, new));
}
