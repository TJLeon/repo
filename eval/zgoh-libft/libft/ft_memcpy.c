/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:49:22 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:26:27 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = (char *)dst;
	source = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(dest + i) = *(source + i);
		++i;
	}
	return (dst);
}
//didn't check overlapping memory
//simply copy the bytes in a straightfoward manner
/*
int	main(void)
{
	char dest[20] = "ello!";
	//char str[20] = "ello!";
	char src[20] = "Hello!";

	ft_memcpy(dest,src,3);
	//memcpy(str,src,1);
	printf("%s\n",dest);
	//printf("%s\n",str);
	return (0);
}
*/
