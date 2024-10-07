/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:15:57 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 11:06:26 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_stack **stack_a)
{
	int		bit;
	t_stack	*stack_b;
	int		len;

	if (stack_a == NULL || *stack_a == NULL)
		ft_kill_switch(NULL, NULL);
	bit = 0;
	stack_b = NULL;
	while (ft_sort_check(*stack_a) == 0)
	{
		len = ft_list_len(*stack_a);
		while (*stack_a != NULL && len-- > 0)
		{
			if ((((*stack_a)->data >> bit) & 1) == 1)
				ft_stack_rot(stack_a, 'a');
			else
				ft_stack_push(stack_a, &stack_b, 'b');
		}
		while (stack_b != NULL)
			ft_stack_push(&stack_b, stack_a, 'a');
		bit++;
	}
}
