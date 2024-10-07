/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:41:56 by leotan            #+#    #+#             */
/*   Updated: 2023/11/10 23:26:49 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		x;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x])
	{
		ptr[i + x] = s2[x];
		x++;
	}
	ptr[i + x] = 0;
	return (ptr);
}
