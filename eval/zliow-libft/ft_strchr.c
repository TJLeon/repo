/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:28 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:15:14 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
		{
			return ((char *)--s);
		}
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
