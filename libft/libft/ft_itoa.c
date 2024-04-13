/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:52:07 by leotan            #+#    #+#             */
/*   Updated: 2024/02/17 18:33:49 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	long	nbr;

	len = count_digit(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	nbr = n;
	if (n < 0)
	{
		ptr[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		ptr[len-- - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	ptr[len - 1] = nbr + 48;
	return (ptr);
}
