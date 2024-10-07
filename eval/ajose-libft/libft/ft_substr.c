/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose <ajose@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:33:31 by ajose             #+#    #+#             */
/*   Updated: 2024/07/21 23:32:09 by ajose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int x, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (x >= ft_strlen(s1))
		return (ft_calloc(1, 1));
	while (s1[x + i] != '\0' && i < len)
		i++;
	s2 = ft_calloc(i + 1, 1);
	if (s2 == NULL || len == 0)
		return (s2);
	i = -1;
	while (s1[x + ++i] != '\0' && i < len)
		s2[i] = s1[x + i];
	return (s2);
}
