/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:09:49 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 15:40:33 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*z;
	unsigned char	character;

	z = NULL;
	character = c;
	while (*s)
	{
		if (*s == character)
			z = (char *)s;
		++s;
	}
	if (*s == character)
		z = (char *)s;
	return (z);
}
/*
by default z is null, if not found the character in string
	>null will be returned
it didn't find from behind, but from infront
	>just the z will keep getting override by address of next c in string
	>until whole string is iterate, value stored in z will be the last c in s
*/
/*
int	main(void)
{
	const char* testString = "This is a test string";
	const char* searchChars = "aeiou";
    printf("Test 1:\n");
    printf("strrchr: %s\n", strrchr(testString, 's'));
    printf("ft_strrchr: %s\n", ft_strrchr(testString, 's'));
    printf("\nTest 2:\n");
    printf("strrchr: %s\n", strrchr(testString, 'i'));
    printf("ft_strrchr: %s\n", ft_strrchr(testString, 'i'));
    printf("\nTest 3:\n");
    printf("strrchr: %s\n", strrchr(testString, 'x'));
    printf("ft_strrchr: %s\n", ft_strrchr(testString, 'x'));
    printf("\nTest 4:\n");
    printf("strrchr: %s\n", strrchr(testString, searchChars[0]));
    printf("ft_strrchr: %s\n", ft_strrchr(testString, searchChars[0]));
    return (0);
}
*/
