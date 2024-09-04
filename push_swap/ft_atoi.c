/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:26:00 by leotan            #+#    #+#             */
/*   Updated: 2024/09/02 16:29:21 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_only_digits(char **s)
{
	unsigned long long	i;
	unsigned long long	x;

	i = -1;
	while (s[++i] != NULL)
	{
		x = -1;
		while (s[i][++x] != '\0')
		{
			if (s[i][x] == '+' || s[i][x] == '-')
				x++;
			while (s[i][x] >= '0' && s[i][x] <= '9')
				x++;
			if (s[i][x] != '\0' || !(s[i][x - 1] >= '0' && s[i][x - 1] <= '9'))
				return (0);
		}
	}
	return (1);
}

static int	ft_int_check(t_stack *p, long long n)
{
	if (n < -2147483648 || n > 2147483647)
		return (1);
	while (p != NULL && p->data != n && p->status != 2)
		p = p->next;
	if (p != NULL && p->data == n)
		return (1);
	return (0);
}

t_stack	*ft_atoi(char **s)
{
	unsigned long long	i;
	unsigned long long	x;
	int					sign;
	long long			r;
	t_stack				*ptr;

	if (s == NULL || ft_only_digits(s) == 0)
		return (ft_free_2d_arr(s));
	i = -1;
	ptr = NULL;
	while (s[++i] != NULL)
	{
		x = 0;
		sign = 1;
		if (s[i][x] == '+' || s[i][x] == '-')
			if (s[i][x++] == '-')
				sign = -1;
		r = 0;
		while (s[i][x] >= '0' && s[i][x] <= '9' && i < 11)
			r = (r * 10) + (s[i][x++] - '0');
		if (ft_int_check(ptr, r * sign))
			return (ft_free_2d_arr(s), ft_free_list(&ptr));
		ptr = ft_list_add_num(ptr, r * sign, s);
	}
	return (ft_free_2d_arr(s), ptr);
}
