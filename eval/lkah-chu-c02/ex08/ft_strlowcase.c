/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <lkah-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:37:45 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 20:39:39 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	i += 1;
	}
	return (str);
}
/*
#include <stdio.h>
int    main(void)
{
    char store[] = "DWDDWDWQ";
    char stora[] = "dwdDWADAdwd";
    char *result = ft_strlowcase(store);
    char *resultt = ft_strlowcase(stora);
    printf("%s\n", result);
 	printf("%s\n", resultt);
	return (0);
}*/
