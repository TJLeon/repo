/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:14:52 by leotan            #+#    #+#             */
/*   Updated: 2024/04/29 16:02:47 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charmatch(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*ptr;
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
	ptr = ft_calloc(end - start + 2, 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = str[start++];
	return (ptr);
}
