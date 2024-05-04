/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:09:47 by leotan            #+#    #+#             */
/*   Updated: 2024/05/03 23:16:30 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (++i < len)
	{
		if (dst > src)
			d[len - 1 - i] = s[len - 1 - i];
		else
			d[i] = s[i];
	}
	return (dst);
}
