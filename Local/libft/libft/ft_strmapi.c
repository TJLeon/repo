/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:44:07 by leotan            #+#    #+#             */
/*   Updated: 2024/05/03 22:07:05 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	p = ft_calloc(ft_strlen(s) + 1, 1);
	if (p == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		p[i] = f(i, s[i]);
	return (p);
}
