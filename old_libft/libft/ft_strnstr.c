/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:12:49 by leotan            #+#    #+#             */
/*   Updated: 2024/05/04 00:36:52 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		x;

	i = -1;
	x = 0;
	if (n == 0 && (s1 == NULL || s2 == NULL))
		return (NULL);
	if (s2[x] == '\0')
		return ((char *)s1);
	while (s1[++i] != '\0' && i < n)
	{
		if (s1[i] == s2[x])
		{
			while ((s1[i + x] == s2[x]) && (s2[x] != '\0' && i + x < n))
				x++;
			if (s2[x] == '\0')
				return ((char *)&s1[i]);
			x = 0;
		}
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
void main()
{
	printf("%s\n",ft_strnstr(((void *)0), "fake", 0));
}*/
