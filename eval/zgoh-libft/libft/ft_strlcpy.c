/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:47:07 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 21:29:04 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < dstsize - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
size: length of dst
//if dst_len >= src_len, means that whole src can be copied successfully
//if dst_len < src_len, means that truncation happen (copied not completely)
in both scenario, src_length will be returned.
*/
/*
int main(void)
{size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !dst)
		return (0);
	if (size != 0)
	{
		i = -1;
		while (++i < size - 1 && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
	char dest[15];
	//dest = "rrrrrr000000000"
	memset(dest,0,15);
	memset(dest,'r',6);

	//printf("%lu",ft_strlcpy(dest, "lorem ipsum", 3));
	// 11 and lo\0rrr\0\0\0\0\0\0\0\0\0

	printf("%lu",ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
	//26 and lorem ipsum do\0

	printf("\n%s\n",dest);
	return (0);
}
*/
