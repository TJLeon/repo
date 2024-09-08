/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:15:57 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 17:58:43 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_binary_check(t_stack *ptr, int digit)
{
	if (ptr == NULL || digit <= 0)
		ft_kill_switch(NULL, ptr);
	while (ptr->status != 2 && (ptr->data / digit) % 2 == 1)
		ptr = ptr->next;
	if ((ptr->data / digit) % 2 == 0)
		return (0);
	return (1);
}

void	ft_radix_sort(t_stack **stack_a)
{
	int		digit;
	t_stack	*stack_b;

	if (stack_a == NULL || *stack_a == NULL)
		ft_kill_switch(NULL, NULL);
	digit = 1;
	stack_b = NULL;
	while (ft_sort_check(*stack_a) == 0)
	{
		while (ft_binary_check(*stack_a, digit) == 0)
		{
			while (((*stack_a)->data / digit) % 2 == 1)
				ft_stack_rot(stack_a, 'a');
			while (((*stack_a)->data / digit) % 2 == 0)
				ft_stack_push(stack_a, &stack_b, 'b');
		}
		while (stack_b != NULL)
			ft_stack_push(&stack_b, stack_a, 'a');
		digit++;
	}
}
