/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:25:15 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 17:45:36 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_blank_input(char **argv)
{
	int	i1;
	int	i2;

	if (argv == NULL)
		ft_kill_switch(NULL, NULL);
	i1 = 0;
	while (argv[++i1] != NULL)
	{
		i2 = 0;
		while (argv[i1][i2] != '\0' && argv[i1][i2] == ' ')
			++i2;
		if (argv[i1][i2] == '\0')
			ft_kill_switch(NULL, NULL);
	}
	return (argv);
}

static void	ft_sort_3_num(t_stack *ptr)
{
	if (ptr == NULL)
		return ;
	if (ptr->data > ptr->next->data && ptr->data < ptr->prev->data)
		return ((void)write(STDOUT_FILENO, "sa\n", 3));
	if (ptr->data > ptr->next->data && ptr->data > ptr->prev->data)
	{
		if (ptr->next->data > ptr->prev->data)
			return ((void)write(STDOUT_FILENO, "sa\nrra\n", 7));
		return ((void)write(STDOUT_FILENO, "ra\n", 3));
	}
	if (ptr->data < ptr->next->data && ptr->data < ptr->prev->data)
	{
		if (ptr->next->data > ptr->prev->data)
			return ((void)write(STDOUT_FILENO, "sa\nra\n", 6));
		return ;
	}
	return ((void)write(STDOUT_FILENO, "rra\n", 4));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = ft_str_to_list(ft_parse_input(ft_blank_input(argv)));
	if (stack_a->next == NULL)
		exit(0);
	if (stack_a->next->status == 2 && stack_a->data > stack_a->next->data)
		return (write(STDOUT_FILENO, "sa\n", 3), ft_free_list(stack_a), 0);
	if (stack_a->next->next->status == 2)
		return (ft_sort_3_num(stack_a), ft_free_list(stack_a), 0);
	stack_a = ft_list_to_index(stack_a);
	ft_radix_sort(&stack_a);
	return (ft_free_list(stack_a), 0);
}
