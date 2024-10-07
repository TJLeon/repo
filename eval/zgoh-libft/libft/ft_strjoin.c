/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:11:08 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/26 03:19:09 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*save;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1) + ft_strlen(s2)));
	if (!new)
		return (NULL);
	save = new;
	while (*s1)
		*(new++) = *(s1++);
	while (*s2)
		*(new++) = *(s2++);
	*new = '\0';
	return (save);
}
