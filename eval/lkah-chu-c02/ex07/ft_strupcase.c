/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <lkah-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:28:31 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 20:39:52 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[0] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	i += 1;
	}
	return (str);
}
/*
#include <stdio.h>
int    main(void)
{
    char store[] = "juwcwqe";
    char stora[] = "hrtdw";
    char *result = ft_strupcase(store);
    char *resultt = ft_strupcase(stora);
    printf("%s\n", result);
 	printf("%s\n", resultt);
	return (0);
}*/
