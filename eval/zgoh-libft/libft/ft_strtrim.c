/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:19:46 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:36:09 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dup_word(char *new, char const *s1, int j)
{
	int	i;

	i = 0;
	while (i < j && *s1)
		new[i++] = *(s1++);
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		len;
	char	*new;

	if (!s1 ||!set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	j = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[j]))
		--j;
	len = j + 1;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new = dup_word(new, s1, len);
	return (new);
}
/*
line 34: check whether current character pointing by s1 is include in set
	>if yes, return 1 from ft_strchr, and move pointer s1
	>pointer s1 will stop at the character that not include in *set
	>also will auto trim away the in front part
line 36: count the leftover length of s1
	>because of previous while loop, pointer have moved
	>j will be the index of last character in s1
line 38: j will continue decrease until hit character not in *set
line 39: after loop, j will be the length of the trimmed string
	>plus one is to fixed the index? or for null terminator?
	>len can directly to be used to malloc new
line 43: dup_word()
	>to copy the trimmed string
*/
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_strtrim("   xxx   xxx", " x"));
	printf("%s\n",ft_strtrim("", "123"));
	printf("%s\n",ft_strtrim("", ""));
	
	return (0);
}
*/
