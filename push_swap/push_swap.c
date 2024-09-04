/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:25:15 by leotan            #+#    #+#             */
/*   Updated: 2024/09/04 09:36:45 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_blank_input(char **argv)
{
	unsigned long long	i;
	unsigned long long	x;

	i = 0;
	while (argv[++i] != NULL)
	{
		x = 0;
		while (argv[i][x] != '\0' && argv[i][x] == ' ')
			++x;
		if (argv[i][x] == '\0')
			return (NULL);
	}
	return (argv);
}

static void	ft_hardcode_for_3(t_stack *ptr)
{
	if (ptr->data > ptr->next->data && ptr->data < ptr->prev->data)
		return ((void)write(1, "sa\n", 3));
	if (ptr->data > ptr->next->data && ptr->data > ptr->prev->data)
	{
		if (ptr->next->data > ptr->prev->data)
			return ((void)write(1, "sa\nrra\n", 7));
		return ((void)write(1, "ra\n", 3));
	}
	if (ptr->data < ptr->next->data && ptr->data < ptr->prev->data)
	{
		if (ptr->next->data > ptr->prev->data)
			return ((void)write(1, "sa\nra\n", 6));
		return ;
	}
	return ((void)write(1, "rra\n", 4));
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = ft_atoi(ft_split(ft_blank_input(argv)));
	if (a == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	if (a->next == NULL)
		return (0);
	if (a->next->status == 2 && a->data > a->next->data)
		return (write(1, "sa\n", 3), (int)ft_free_list(&a));
	if (a->next->next->status == 2)
		return (ft_hardcode_for_3(a), (int)ft_free_list(&a));
	while (ft_sort_check(a) == 0)
	{
		;
	}
	return ((int)ft_free_list(&a));
}
