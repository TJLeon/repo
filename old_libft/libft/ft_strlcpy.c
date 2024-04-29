/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:33:44 by leotan            #+#    #+#             */
/*   Updated: 2024/04/29 15:53:53 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i + 1 < dstsize)
			dst[i] = src[i];
		else if (dstsize != 0 && i < dstsize)
			dst[i] = '\0';
		i++;
	}
	if (dstsize != 0 && i < dstsize)
		dst[i] = '\0';
	return (i);
}
