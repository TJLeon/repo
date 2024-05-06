/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:09:47 by leotan            #+#    #+#             */
/*   Updated: 2024/05/05 13:33:03 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (++i < len)
	{
		if (dst > src)
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
		else
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
