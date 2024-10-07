/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:28:18 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 21:29:46 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*start;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (str != NULL)
	{
		start = str;
		while (*s1)
			*(str++) = *(s1++);
		*str = '\0';
		return (start);
	}
	return (NULL);
}
/*
int	main(void)
{
	char s[10] = "Hello";
	printf("%s\n",ft_strdup(s));
	return (0);
}
*/
