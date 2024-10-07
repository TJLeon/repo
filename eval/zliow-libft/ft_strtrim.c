/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 02:27:27 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:15:36 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_isinset(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_isinset(s1[len - 1], set))
		len--;
	trim = ft_substr(s1, 0, len);
	return (trim);
}
