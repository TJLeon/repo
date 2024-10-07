/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:33:20 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/11 04:12:42 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 char f(unsigned int i, char *str)
 {
 	printf("My inner function: index = %d and %c\n", i, str);
 	return (str - 32);
 }
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}
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
