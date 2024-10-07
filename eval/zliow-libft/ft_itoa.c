/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 02:26:14 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 02:26:23 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	n_len;
	unsigned int	n_cpy;

	n_len = ft_number_size(n);
	n_cpy = n;
	if (n < 0)
		n_cpy = -n;
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	while (n_len--)
	{
		str[n_len] = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
