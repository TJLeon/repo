/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:38 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 15:36:49 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_setup(t_stack **from, t_stack **to)
{
	if (*to != NULL)
	{
		if ((*to)->next != NULL)
		{
			(*to)->prev->next = *from;
			(*to)->prev = *from;
			(*to)->status = 1;
		}
		else
		{
			(*to)->next = *from;
			(*to)->prev = *from;
			(*to)->status = 2;
		}
	}
	else
		*to = *from;
}

static void	push_util(t_stack **from, t_stack **to)
{
	if ((*from)->next != NULL)
	{
		(*from)->next->status = 0;
		if ((*from)->next == (*from)->prev)
		{
			(*from)->next->next = NULL;
			(*from)->next->prev = NULL;
		}
		else
		{
			(*from)->next->prev = (*from)->prev;
			(*from)->prev->next = (*from)->next;
		}
	}
	if (*to != *from)
	{
		(*from)->next = *to;
		*from = (*from)->prev;
		if (*from != NULL && (*from)->next != NULL)
			*from = (*from)->next;
		*to = (*to)->prev;
		(*to)->prev = ft_find_tail(*to);
	}
	else
		*from = (*from)->next;
}

void	ft_stack_push(t_stack **from, t_stack **to, char s)
{
	if (*from == NULL)
		return ;
	push_setup(from, to);
	push_util(from, to);
	if ((*to)->next == *from)
	{
		(*to)->next = NULL;
		(*to)->prev = NULL;
	}
	write(STDOUT_FILENO, "p", 1);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}
