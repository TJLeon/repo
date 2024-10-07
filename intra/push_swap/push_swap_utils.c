/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:23:35 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 17:23:39 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_ptr(void **ptr)
{
	int	i;

	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (ptr[++i] != NULL)
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

void	*ft_free_list(t_stack *ptr)
{
	t_stack	*temp;

	if (ptr == NULL)
		return (NULL);
	while (ptr->status != 0)
		ptr = ptr->prev;
	while (ptr->status != 2 && ptr->next != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	free(ptr);
	return (NULL);
}

void	ft_kill_switch(void **p1, t_stack *p2)
{
	if (p1 != NULL)
		ft_free_ptr(p1);
	if (p2 != NULL)
		ft_free_list(p2);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
