/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:57:03 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:14:56 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		d = dst + len;
		s = src + len;
		while (len-- > 0)
			*(--d) = *(--s);
	}
	else
	{
		d = dst;
		s = src;
		while (len-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
