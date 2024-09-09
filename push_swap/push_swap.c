/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:25:15 by leotan            #+#    #+#             */
/*   Updated: 2024/09/09 14:13:05 by leotan           ###   ########.fr       */
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

static void	ft_sort_3_num(t_stack **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	if ((*ptr)->data > (*ptr)->next->data && (*ptr)->data < (*ptr)->prev->data)
		return (ft_stack_swap(*ptr, 'a'));
	if ((*ptr)->data > (*ptr)->next->data && (*ptr)->data > (*ptr)->prev->data)
	{
		if ((*ptr)->next->data > (*ptr)->prev->data)
			return (ft_stack_swap(*ptr, 'a'), ft_stack_rrot(ptr, 'a'));
		return (ft_stack_rot(ptr, 'a'));
	}
	if ((*ptr)->data < (*ptr)->next->data && (*ptr)->data < (*ptr)->prev->data)
	{
		if ((*ptr)->next->data > (*ptr)->prev->data)
			return (ft_stack_swap(*ptr, 'a'), ft_stack_rot(ptr, 'a'));
		return ;
	}
	return (ft_stack_rrot(ptr, 'a'));
}

static void	ft_sort_small(t_stack **s_a)
{
	int		len;
	t_stack	*stack_b;

	len = ft_list_len(*s_a);
	while (ft_list_len(*s_a) > 3 && ft_sort_check(*s_a) == 0)
	{
		if ((*s_a)->data == 0 || (*s_a)->data == len - 1)
			ft_stack_push(s_a, &stack_b, 'b');
		else if ((*s_a)->prev->data == 0 || (*s_a)->prev->data == len - 1)
		{
			ft_stack_rrot(s_a, 'a');
			ft_stack_push(s_a, &stack_b, 'b');
		}
		else if ((*s_a)->next->data == 0 || (*s_a)->next->data == len - 1)
		{
			ft_stack_rot(s_a, 'a');
			ft_stack_push(s_a, &stack_b, 'b');
		}
		else
			ft_stack_rot(s_a, 'a');
	}
	ft_sort_3_num(s_a);
	while (stack_b != NULL)
		ft_stack_push(&stack_b, s_a, 'a');
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
		return (ft_stack_swap(stack_a, 'a'), ft_free_list(stack_a), 0);
	if (stack_a->next->next->status == 2)
		return (ft_sort_3_num(&stack_a), ft_free_list(stack_a), 0);
	stack_a = ft_list_to_index(stack_a);
	if (ft_list_len(stack_a) <= 5)
		ft_sort_small(&stack_a);
	else
		ft_radix_sort(&stack_a);
	return (ft_free_list(stack_a), 0);
}
