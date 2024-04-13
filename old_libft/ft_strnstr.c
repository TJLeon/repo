/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:12:49 by leotan            #+#    #+#             */
/*   Updated: 2023/11/10 21:33:21 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	if (n == 0 && (!s1 || !s2))
		return (NULL);
	if (s2[x] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[x])
		{
			while ((s1[i + x] == s2[x]) && (s2[x] != '\0' && i + x < n))
				x++;
			if (s2[x] == '\0')
				return ((char *)&s1[i]);
			else
				x = 0;
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
void main()
{
	printf("%s\n",ft_strnstr(((void *)0), "fake", 0));
}*/
