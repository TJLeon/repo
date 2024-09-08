/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:28:58 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 15:53:09 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_list_len(t_stack *ptr)
{
	int	len;

	if (ptr == NULL)
		ft_kill_switch(NULL, NULL);
	len = 0;
	while (ptr->status != 2)
	{
		ptr = ptr->next;
		len++;
	}
	len++;
	return (len);
}

static int	*ft_list_to_tab(t_stack *ptr)
{
	int	*tab;
	int	index;

	if (ptr == NULL)
		ft_kill_switch(NULL, NULL);
	tab = malloc(ft_list_len(ptr) * sizeof(int));
	if (tab == NULL)
		ft_kill_switch(NULL, NULL);
	index = 0;
	while (ptr->status != 2)
	{
		tab[index++] = ptr->data;
		ptr = ptr->next;
	}
	tab[index] = ptr->data;
	return (tab);
}

static void	ft_sort_int_tab(int *tab, int len)
{
	int	index;
	int	temp;

	index = 0;
	while (index < len - 1)
	{
		if (tab[index] > tab[index + 1])
		{
			temp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = temp;
			index = 0;
		}
		index++;
	}
}

static void	ft_num_to_index(t_stack *ptr, t_stack *copy, int num, int index)
{
	while (ptr->data != num)
	{
		ptr = ptr->next;
		copy = copy->next;
	}
	copy->data = index;
}

t_stack	*ft_list_to_index(t_stack *ptr)
{
	int		*tab;
	int		len;
	int		index;
	t_stack	*copy;

	if (ptr == NULL)
		ft_kill_switch(NULL, NULL);
	tab = ft_list_to_tab(ptr);
	len = ft_list_len(ptr);
	ft_sort_int_tab(tab, len);
	copy = ft_list_dupe(ptr);
	index = -1;
	while (++index < len)
		ft_num_to_index(ptr, copy, tab[index], index);
	free(tab);
	while (copy->status != 0)
		copy = copy->prev;
	return (ft_free_list(ptr), copy);
}
