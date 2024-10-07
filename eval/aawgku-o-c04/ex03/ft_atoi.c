/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:53:19 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/09/27 19:17:45 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	xoxo;

	result = 0;
	sign = 1;
	xoxo = 0;
	while (str[xoxo] == ' ' || str[xoxo] == '\t' || str[xoxo] == '\n'
		|| str[xoxo] == '\r' || str[xoxo] == '\f' || str[xoxo] == '\v')
		xoxo++;
	while (str[xoxo] == '-' || str[xoxo] == '+')
	{
		if (str[xoxo] == '-')
			sign *= -1;
		xoxo++;
	}
	while (str[xoxo] >= '0' && str[xoxo] <= '9')
	{
		result = result * 10 + str[xoxo] - '0';
		xoxo++;
	}
	result *= sign;
	return (result);
}

int main() 
{
    char *str = "  ---1234ab567";
    int num = ft_atoi(str);
    printf("Converted number: %d\n", num);

    return (0);
}
