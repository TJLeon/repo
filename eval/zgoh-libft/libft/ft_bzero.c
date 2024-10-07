/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:32:48 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 20:34:09 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//write n zero bytes to the string s
//do nothing when n = 0

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		*(str++) = '\0';
		++i;
	}
}
/*
int	main(void)
{
	int i;

	char s[20] = "Hello World";
	//bzero(s,5);
	ft_bzero(s,5);
	for(i = 0; i < 20; ++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	return (0);
}
*/
