/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:36:43 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 20:32:17 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
/*
int	main(void)
{
	char	str[] = "Hello!";

	printf("%zu\n", ft_strlen(str));
	printf("%zu\n", strlen(str));
	printf("%ld\n",ft_strlen(str));
	return (0);
}
*/
