/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:12:38 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 15:11:16 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	isolate_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->status == 2)
		{
			stack->next = NULL;
			stack->prev = NULL;
		}
		else
		{
			stack->prev = ft_find_tail(stack);
			stack->prev->next = stack;
		}
		stack->status = 0;
	}
}

static void	add_head(t_stack *stack, t_stack *temp)
{
	if (stack != NULL)
	{
		if (stack->next == NULL)
		{
			stack->status = 2;
			stack->next = temp;
			stack->prev = temp;
		}
		else
		{
			stack->status = 1;
			stack->prev->next = temp;
			stack->prev = temp;
		}
		temp->next = stack;
		temp->prev = ft_find_tail(stack);
	}
	else
	{
		temp->next = NULL;
		temp->prev = NULL;
	}
}

void	ft_stack_push(t_stack **from, t_stack **to, char s)
{
	t_stack	*temp;

	temp = *from;
	*from = (*from)->next;
	isolate_stack(*from);
	add_head(*to, temp);
	*to = temp;
	write(STDOUT_FILENO, "p", 1);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}
