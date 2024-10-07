/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:03:41 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 00:06:05 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'A' && *str <= 'Z')))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
#include <stdio.h>
int    main(void)
{
    char *store = "ASDwcwqe";
    char *stora = "ADSAF";
    int result = ft_str_is_uppercase(store);
    int resultt = ft_str_is_uppercase(stora);
    printf("%d", result);
    printf("%d", resultt);
}*/
