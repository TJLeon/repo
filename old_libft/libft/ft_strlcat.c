/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:42:55 by leotan            #+#    #+#             */
/*   Updated: 2024/04/29 15:53:20 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (dst != NULL && dst[i] != '\0' && i < dstsize)
		i++;
	x = 0;
	while (src[x] != '\0')
	{
		if ((x + i + 1) < dstsize)
			dst[i + x] = src[x];
		else if (dstsize != 0 && i + x < dstsize)
			dst[i + x] = '\0';
		x++;
	}
	if (dstsize != 0 && i + x < dstsize)
		dst[i + x] = '\0';
	if (dstsize <= i)
		return (dstsize + x);
	return (i + x);
}
