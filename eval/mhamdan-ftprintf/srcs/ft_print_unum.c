/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:31:10 by mhamdan           #+#    #+#             */
/*   Updated: 2023/11/29 17:56:20 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		len--;
		num[len] = n % 10 + 48;
		n = n / 10;
	}
	return (num);
}

int	ft_print_unum(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else
	{
		num = ft_uitoa(n);
		len += ft_print_str(num);
		free(num);
	}
	return (len);
}
