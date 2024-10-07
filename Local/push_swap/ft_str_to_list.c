/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:26:00 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 22:34:24 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_only_num(char **s)
{
	int	i;
	int	x;

	i = -1;
	while (s[++i] != NULL)
	{
		x = 0;
		while (s[i][x] != '\0')
		{
			if (s[i][x] == '+' || s[i][x] == '-')
				x++;
			while (s[i][x] >= '0' && s[i][x] <= '9')
				x++;
			if (s[i][x] != '\0' || !(s[i][x - 1] >= '0' && s[i][x - 1] <= '9'))
				ft_kill_switch((void **)s, NULL);
		}
	}
}

static void	ft_int_check(t_stack *ptr, long num, char **str)
{
	if (str == NULL)
		ft_kill_switch(NULL, ptr);
	if (num < -2147483648 || num > 2147483647)
		ft_kill_switch((void **)str, ptr);
	while (ptr != NULL && ptr->data != num && ptr->status != 2)
		ptr = ptr->next;
	if (ptr != NULL && ptr->data == num)
		ft_kill_switch((void **)str, ptr);
}

t_stack	*ft_str_to_list(char **str)
{
	int		i1;
	int		i2;
	int		sign;
	long	num;
	t_stack	*ptr;

	if (str == NULL)
		ft_kill_switch(NULL, NULL);
	ft_only_num(str);
	i1 = -1;
	ptr = NULL;
	while (str[++i1] != NULL)
	{
		i2 = 0;
		sign = 1;
		if (str[i1][i2] == '+' || str[i1][i2] == '-')
			if (str[i1][i2++] == '-')
				sign = -1;
		num = 0;
		while (str[i1][i2] >= '0' && str[i1][i2] <= '9' && i2 < 11)
			num = (num * 10) + (str[i1][i2++] - '0');
		ft_int_check(ptr, num * sign, str);
		ptr = ft_list_add_num(ptr, num * sign, str);
	}
	return (ft_free_ptr((void **)str), ptr);
}
