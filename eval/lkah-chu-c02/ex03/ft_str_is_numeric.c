/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:37:34 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/19 23:52:23 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
#include <stdio.h>

int main(void)
{
	char *str1 = "2313";
	char *str2 = "dasd";
	int result1 = ft_str_is_numeric(str1);
	int result2 = ft_str_is_numeric(str2);
	printf("shud be 1:%d\n", result1);
	printf("shud be 0:%d\n", result2);
}*/
