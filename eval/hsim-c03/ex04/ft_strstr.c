/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:04:54 by hsim              #+#    #+#             */
/*   Updated: 2023/09/30 21:50:07 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (*to_find == '\0')
		return (str);
	while (str[a] != '\0')
	{
		if (str[a] == to_find[b])
		{
			a++;
			b++;
			if (to_find[b] == '\0')
				return (&str[a - b]);
		}
		else
		{
			b = 0;
			a++;
		}
	}	
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char *c;
	c = ft_strstr("Helzzz Hellloz", "Hell");
	printf("%s", c);
}
*/
