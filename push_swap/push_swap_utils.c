/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:23:35 by leotan            #+#    #+#             */
/*   Updated: 2024/09/02 16:30:06 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free_2d_arr(char **s)
{
	unsigned long long	i;

	i = -1;
	while (s[++i] != NULL)
		free(s[i]);
	free(s);
	return (NULL);
}

void	*ft_free_list(t_stack **p)
{
	t_stack	*t;

	while ((*p)->status != 2 && (*p)->next != NULL)
	{
		t = *p;
		*p = (*p)->next;
		free(t);
	}
	if (*p != NULL)
		free(*p);
	*p = NULL;
	return (NULL);
}
