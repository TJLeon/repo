/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:10:46 by leotan            #+#    #+#             */
/*   Updated: 2024/09/02 16:41:43 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_linkedlist
{
	int					data;
	struct s_linkedlist	*next;
	struct s_linkedlist	*prev;
	int					status;
}	t_stack;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t t);
void	*ft_free_2d_arr(char **s);
char	**ft_split(char **argv);
void	*ft_free_list(t_stack **p);
t_stack	*ft_list_add_num(t_stack *p, long long n, char **s);
t_stack	*ft_atoi(char **s);

#endif
