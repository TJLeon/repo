/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:54:46 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 15:33:07 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = c;
	while (*s)
	{
		if (*s == character)
			return ((char *)s);
		++s;
	}
	if (*s == character && character == '\0')
		return ((char *)s);
	return (NULL);
}
/*
unsigned char is used
	>ensure it only handle character within ASCII table
	>in other word, restrict the search to ASCII characters
line 26 & 27: deal when c == '\0'
	>it will return s that pointing to \0
*/
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
    const char* testString = "This is a test string";
    const char* searchChars = "aeiou";

    printf("Test 1:\n");
    printf("strchr: %s\n", strchr(testString, 'a'));
    printf("ft_strchr: %s\n", ft_strchr(testString, 'a'));
    printf("\nTest 2:\n");
    printf("strchr: %s\n", strchr(testString, 'i'));
    printf("ft_strchr: %s\n", ft_strchr(testString, 'i'));
    return (0);
}
*/
