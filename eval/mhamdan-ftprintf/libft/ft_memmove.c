/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:11:36 by mhamdan           #+#    #+#             */
/*   Updated: 2023/10/22 22:18:19 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst)
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
