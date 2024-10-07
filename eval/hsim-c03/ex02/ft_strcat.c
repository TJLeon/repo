/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:09:45 by hsim              #+#    #+#             */
/*   Updated: 2023/09/30 21:11:52 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0')
		dest[a++] = src[b++];
	dest[a] = '\0';
	return (dest);
}


#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[20] = "Hello";
	char source[] = "i";
	//char *y;

	strcat(dest, source);
	printf("%s\n", dest);
}

