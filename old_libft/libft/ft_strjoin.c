/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:41:56 by leotan            #+#    #+#             */
/*   Updated: 2024/05/05 16:20:02 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		x;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (p == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	x = -1;
	while (s2[++x] != '\0')
		p[i + x] = s2[x];
	return (p);
}
