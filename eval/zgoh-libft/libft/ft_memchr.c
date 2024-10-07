/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:46:59 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:22:34 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i++ < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		++str;
	}
	return (NULL);
}
//unsigned is recommend to use when compare memory
//	>because we don't want use negative value
/*
#include <string.h>
int main()
{
	char			*src = "/|\x12\xff\x09\x42\2002\42|\\";
	int				size = 10;


	printf("%s\n",(char *)ft_memchr(src, '\200', size));
	printf("%s\n",(char *)memchr(src, '\200', size));
    return (0);
}
*/
