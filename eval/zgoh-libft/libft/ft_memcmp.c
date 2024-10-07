/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:21:21 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/08 17:06:36 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*second;

	one = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1))
	{
		if (one[i] == second[i])
			++i;
		else
			break ;
	}
	return (one[i] - second[i]);
}
//this is not only compare for string
/*
#include <string.h>
int	main(void)
{
	//char s1[] = "HEllo";
	//char s2[] = "HEllO";

	char	*s1 = "atoms\0\0\0\0";
	char	*s2 = "atoms\0abc";
	size_t	size = 8;

	//printf("%d\n",ft_memcmp(s1,s2,5));
	//printf("%d\n",memcmp(s1,s2,5));
	printf("%d\n",memcmp(s1,s2,size));
	printf("%d\n",ft_memcmp(s1,s2,size));
	return (0);
}
*/
