/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:46:51 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 10:31:14 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_check(t_stack *ptr)
{
	if (ptr == NULL)
		ft_kill_switch(NULL, NULL);
	while (ptr->status != 2 && ptr->data < ptr->next->data)
		ptr = ptr->next;
	if (ptr->status == 2 && ptr->data > ptr->next->data)
		return (1);
	return (0);
}

static t_stack	*ft_node_copy(t_stack *ptr, t_stack *copy, t_stack *temp)
{
	temp->status = ptr->status;
	temp->data = ptr->data;
	temp->prev = copy;
	if (copy != NULL)
		copy->next = temp;
	copy = temp;
	return (copy);
}

t_stack	*ft_list_dupe(t_stack *ptr)
{
	t_stack	*copy;
	t_stack	*temp;

	copy = NULL;
	while (ptr->status != 2)
	{
		temp = malloc(sizeof(t_stack));
		if (temp == NULL)
			ft_kill_switch(ft_free_list(copy), ptr);
		copy = ft_node_copy(ptr, copy, temp);
		ptr = ptr->next;
	}
	temp = malloc(sizeof(t_stack));
	if (temp == NULL)
		ft_kill_switch(ft_free_list(copy), ptr);
	copy = ft_node_copy(ptr, copy, temp);
	while (copy->status != 0)
		copy = copy->prev;
	temp->next = copy;
	copy->prev = temp;
	return (copy);
}

t_stack	*ft_find_tail(t_stack *stack)
{
	while (stack->status != 2)
		stack = stack->next;
	return (stack);
}

int	ft_list_len(t_stack *ptr)
{
	int	len;

	len = 0;
	while (ptr != NULL && ptr->status != 2)
	{
		ptr = ptr->next;
		len++;
	}
	if (ptr != NULL)
		len++;
	return (len);
}
