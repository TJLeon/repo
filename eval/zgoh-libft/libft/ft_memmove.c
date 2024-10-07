/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:07:15 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:29:15 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		i;

	dest = (char *)dst;
	source = (const char *)src;
	i = len - 1;
	if (!dst && !src)
		return (0);
	if (src > dst)
	{
		while (len-- > 0)
			*(dest++) = *(source++);
	}
	else
	{
		while (i < len)
		{
			*(dest + i) = *(source + i);
			--i;
		}
	}
	return (dst);
}
/*
//check for overlapping memory issue
//have two way of copying bytes:
	>if src & dst is overlapping, it will copy in safer way(2nd while loop)
	>if not, it will just copy (1st while loop)
//safer way:
	>actually is start to copy from behind, and go forward
	>from right to left
*/
/*
int	main(void)
{
	char dest[20] = "ello!";
	char str[20] = "ello!";
	char src[20] = "Hello!";

	ft_memmove(dest,src,0);
	memmove(str,src,0);
	printf("%s\n",dest);
	printf("%s\n",str);
	return (0);
}
*/
