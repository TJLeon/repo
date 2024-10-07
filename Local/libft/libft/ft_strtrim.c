/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:14:52 by leotan            #+#    #+#             */
/*   Updated: 2024/05/05 16:22:23 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charmatch(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*p;
	int		start;
	int		end;
	int		i;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (ft_charmatch(str[start], set))
		start++;
	while (ft_charmatch(str[end], set) && end > start)
		end--;
	p = ft_calloc(end - start + 2, 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		p[i++] = str[start++];
	return (p);
}
