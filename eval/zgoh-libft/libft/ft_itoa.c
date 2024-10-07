/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 03:30:53 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/08 16:48:35 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//digits(): count the number of digit of n
//	~return extra one when n is negative (to put the '-')

static int	digits(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
		if (n < 0)
			n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;
	int		sign;

	sign = 0;
	nbr = (long)n;
	len = digits(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (len > 0)
	{
		str[--len] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (sign == 1)
		str[len] = '-';
	return (str);
}
/*
//nbr declare as long type to avoid overflow problem
//len used to store number of digits and later use as index
line 49: null terminator is set ahead, because len will be modified ltr
*/
