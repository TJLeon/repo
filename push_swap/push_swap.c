/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:25:15 by leotan            #+#    #+#             */
/*   Updated: 2024/08/15 03:44:12 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char **argv)
{
}

struct t_stack	*ft_atoi(char **str)
{
}

int	main(int argc, char **argv)
{
	struct t_stack	*ptr;

	if (argc < 2)
		return (0);
		ptr = ft_atoi(ft_split(argv));
	if (ptr == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), 1);
}

//' ''+''-'
