/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:15:34 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/01 00:41:14 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (len != 0 && haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			++j;
		if (needle[j] == '\0')
			return ((char *)(&haystack[i]));
		++i;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char	*s1 = "see FF your FF return FF now FF";
	char	*s2 = "FF";
	size_t	max = strlen(s1);

	char	*i1 = strnstr(s1, s2, max);
	char	*i2 = ft_strnstr(s1, s2, max);
	printf("%s\n",i1);
	printf("%s\n",i2);

	char haystack[30] = "aaabcabcd"
	char needle[10] = "cd"

	char	*i1 = ;
	char	*i2 = );
	printf("%s\n",strnstr(s1, s2, 8));
	printf("%s\n",ft_strnstr(s1, s2, 8);
}
*/
/*
line 26: another check whether exceed the length, when comparing the needle;
	>need i + j because when enter compare stage, i will remain same
*/
