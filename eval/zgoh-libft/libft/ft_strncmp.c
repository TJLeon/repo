/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:13:26 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:34:21 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && *str1 && *str2)
	{
		if (*(str1++) == *(str2++))
			++i;
		else
			return (*(--str1) - *(--str2));
	}
	return (*str1 - *str2);
}
/*
int	main(void)
{
	//char s1[] = "HEllo";
	//char s2[] = "HEllO";

	//printf("%d\n",ft_strncmp(s1,s2,5));
	// printf("%d\n",ft_strncmp("test", "testss", 7));
	// printf("%d\n",ft_strncmp("testss", "test", 7));
	printf("%d\n",ft_strncmp("test", "tEst", 4));
	printf("%d\n",ft_strncmp("test\200", "test\0", 6));

	return (0);
}
*/
