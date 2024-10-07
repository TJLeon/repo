/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 02:28:00 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:15:10 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			++count;
			while (*s != 0 && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	k;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (length(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			k = 0;
			while (*s && *s != c && ++k)
				++s;
			str[i++] = ft_substr(s - k, 0, k);
		}
		else
			++s;
	}
	str[i] = NULL;
	return (str);
}
