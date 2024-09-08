/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:45:20 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 17:45:44 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rot(t_stack **stack, char s)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	(*stack)->status = 2;
	(*stack)->next->status = 0;
	if ((*stack)->next != (*stack)->prev)
		(*stack)->prev->status = 1;
	*stack = (*stack)->next;
	write(STDOUT_FILENO, "r", 1);
	if (s != 0)
		write(STDOUT_FILENO, &s, 1);
	write(STDOUT_FILENO, "\n", 1);
}
