/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:17:24 by leotan            #+#    #+#             */
/*   Updated: 2024/05/05 16:15:47 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = -1;
	s2 = ft_calloc(ft_strlen(s1) + 1, 1);
	if (s2 == NULL)
		return (s2);
	while (s1[++i] != '\0')
		s2[i] = s1[i];
	return (s2);
}
