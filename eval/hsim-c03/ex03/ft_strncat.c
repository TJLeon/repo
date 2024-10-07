/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:03:23 by hsim              #+#    #+#             */
/*   Updated: 2023/09/30 21:12:38 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < nb)
		dest[a++] = src[b++];
	dest[a] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *c;
	char dest[20] = "Holllow ";
	int n;
	char source[] = "World";

	n = 4;
	c = ft_strncat(dest, source, n);
//	c = strncat(dest, source, n);
	printf("%s", c);

}
*/

/*
appends src to the end of dest, then add '\0'

*/
