/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:57:13 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:15:32 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	length = ft_strlen(needle);
	if (length == 0)
	{
		return ((char *)haystack);
	}
	while (i < len && haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j] && i
			+ j < len)
		{
			j++;
		}
		if (j == length)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
