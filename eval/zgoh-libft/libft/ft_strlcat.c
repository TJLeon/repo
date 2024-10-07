/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:24:25 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 21:29:27 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	if (!dst && dstsize == 0)
		return (0);
	i = 0;
	j = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && dstsize > dst_len + i + 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (src_len + dst_len);
}
/*
size: the expected length of concatenated string
//if size <= dst_len, means there no more space to concatenate src
	>so we returned the size + src_len
//normally src_len plus dst_len will be returned
line 30: size > dst_len + i + 1
	> because size - dst_len = src_len + null
	>so, 1 is the place for null terminator
	>i actually refer to src_len
*/
/*
#include <string.h>
int	main(void)
{
	char	dest[15];
	//char	dest[15] = "rrrrrr000000000";
	memset(dest, 0, 15);
	memset(dest, 'r', 6);

	// memset(dest,'r',14);
	// dest[14] = '\0';
	// printf("%lu\n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));

	// memset(dest, 'r', 15);
	// printf("%lu\n",ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));

	//dest[11] = 'a';
	//printf("%lu\n",ft_strlcat(dest, "lorem", 15));
	//expected: 11 and "rrrrrrlorem\0\0\0\0"

	// dest[0] = '\0';
	// dest[11] = 'a';
	// printf("%lu\n",ft_strlcat(dest, "lorem ipsum", 15));
	//expected: 11 and "lorem ipsum\0\0\0\0"

	//printf("%lu\n",ft_strlcat(dest, "lorem ipsum", 0));
	//printf("%lu\n",strlcat(dest, "lorem ipsum", 0));

	printf("%s",dest);
	return (0);
}
*/
