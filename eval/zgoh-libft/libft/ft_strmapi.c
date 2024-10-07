/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 03:46:31 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/02 17:26:48 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 char f(unsigned int i, char str)
 {
 	printf("index：%d", i);
	printf("%c\n",str);
 	return (str - 32);
 }
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*checkp;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	checkp = str;
	while (*s)
		*(str++) = f(i++, *(s++));
	*str = '\0';
	return (checkp);
}

/*
line 29 & 30: check if parameter valid
checkp: is pointing at the first character, just to avoid get lost
line 37: while *s not reached the end
	>f() will keep calling
	>value return by f() later will store in *str
	>so, str is the new string resulting from successive apply f()
*/
/*
 int main()
 {
	char str[10] = "hello.";
 	printf("The result is %s\n", str);
 	char *result = ft_strmapi(str, f);
 	printf("The result is %s\n", result);
 	return 0;
 }
 */
