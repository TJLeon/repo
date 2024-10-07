/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:54:03 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 00:01:05 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z')))
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
    char *store = "wcwqe";
    char *stora = "sdADSA";
    int result = ft_str_is_lowercase(store);
    int resultt = ft_str_is_lowercase(stora);
    printf("%d", result);
    printf("%d", resultt);
}*/
