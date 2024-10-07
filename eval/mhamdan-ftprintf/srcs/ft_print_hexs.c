/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:31:29 by mhamdan           #+#    #+#             */
/*   Updated: 2023/11/18 18:06:07 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_hex(unsigned int num, int alph)
{
	int		i;
	int		j;
	int		temp;
	char	hex[150];

	i = 1;
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + alph;
		hex[i++] = temp;
		num /= 16;
	}
	j = --i;
	while (j > 0)
		ft_print_char(hex[j--]);
	return (i);
}

int	ft_print_low_hex(unsigned int num)
{
	if (num == 0)
		return (ft_print_char('0'));
	return (convert_to_hex(num, 87));
}

int	ft_print_upp_hex(unsigned int num)
{
	if (num == 0)
		return (ft_print_char('0'));
	return (convert_to_hex(num, 55));
}
