/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:10:46 by leotan            #+#    #+#             */
/*   Updated: 2024/09/24 22:23:02 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int				status;
}	t_stack;

void	*ft_free_ptr(void **ptr);
void	*ft_free_list(t_stack *ptr);
void	ft_kill_switch(void **p1, t_stack *p2);
void	ft_bzero(void *ptr, size_t size);
void	*ft_calloc(size_t size, size_t byte);
char	**ft_parse_input(char **argv);
t_stack	*ft_list_add_num(t_stack *ptr, long num, char **str);
t_stack	*ft_list_dupe(t_stack *ptr);
t_stack	*ft_str_to_list(char **str);
int		ft_list_len(t_stack *ptr);
t_stack	*ft_list_to_index(t_stack *ptr);
int		ft_sort_check(t_stack *ptr);
t_stack	*ft_find_tail(t_stack *s);
void	ft_stack_swap(t_stack *stack, char s);
void	ft_stack_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_stack_push(t_stack **from, t_stack **to, char s);
void	ft_stack_rot(t_stack **stack, char s);
void	ft_stack_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_stack_rrot(t_stack **stack, char s);
void	ft_stack_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_radix_sort(t_stack **stack_a);

#endif
