/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:45:20 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 12:30:55 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rot(t_stack **stack, char s)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->status != 2)
		(*stack)->prev->status = 1;
	(*stack)->status = 2;
	(*stack)->next->status = 0;
	*stack = (*stack)->next;
	if (s == 0)
		return ;
	write(STDOUT_FILENO, "r", 1);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_stack_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_rot(stack_a, 0);
	ft_stack_rot(stack_b, 0);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	ft_stack_rrot(t_stack **stack, char s)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->status != 2)
		(*stack)->status = 1;
	(*stack)->prev->prev->status = 2;
	(*stack)->prev->status = 0;
	*stack = (*stack)->prev;
	if (s == 0)
		return ;
	write(STDOUT_FILENO, "rr", 2);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_stack_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_rrot(stack_a, 0);
	ft_stack_rrot(stack_b, 0);
	write(STDOUT_FILENO, "rrr\n", 4);
}
