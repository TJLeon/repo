/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:01:32 by zliow             #+#    #+#             */
/*   Updated: 2023/09/30 20:56:34 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < size && dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

#include <stdio.h>
#include <string.h>

int	main()
{
	char	destination[25];
	char	destination1[25];
	char	source[] = "blhasjkdfhdsjkfe";
	unsigned int	size = 0;

	printf("Original strlcat: %lu | %s\n", strlcat(destination, source, size), destination);
	printf("Ft_strlcat result: %d | %s\n", ft_strlcat(destination1, source, size), destination1);

	return (0);
}
