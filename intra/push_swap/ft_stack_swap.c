/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:37:22 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 13:02:19 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *stack, char s)
{
	int	temp;

	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (s == 0)
		return ;
	write(STDOUT_FILENO, "s", 1);
	write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_stack_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_stack_swap(stack_a, 0);
	ft_stack_swap(stack_b, 0);
	write(STDOUT_FILENO, "ss\n", 3);
}
