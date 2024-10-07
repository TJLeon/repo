/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:54:26 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 15:26:17 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*
line 19: check whether s is valid or NULL
line 21: check whether the index given is exceed the len of s,
	>if is, start is invalid, so the substring contain nothing (null)
line 29: recount len that is available in s, start from 'start' position
	>if len greater than len that recount
	>reassign value of len
	>if no reassign value, then extra character will be copied
	>this ensure that only available character been copied
	>avoid accessing memory outside the range of s 
line 32: use another function to create substring
	>'s + start', move the pointer based on value of start
	>'len + 1', plus one for null
*/
/*
int	main(void)
{
	char str[] = "lorem ipsum dolor sit amet";
	char	*strsub;

	strsub = ft_substr(str,0,10);
	//expected: lorem ipsu

	//strsub = ft_substr(str,7,10);
	//expected: psum dolor
	if (!strsub)
		printf("is null\n");
	printf("%s\n",strsub);
	return (0);
}
*/
