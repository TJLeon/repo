/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:03:56 by zliow             #+#    #+#             */
/*   Updated: 2023/09/23 01:01:39 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
int	main(int ac, char **av)
{
	char dst1[10];
	char dst2[10];
	if (ac == 3)
	{
	printf("%u\n", ft_strlcpy(dst1, av[1], atoi(av[2])));
	printf("%s\n", dst1);
	printf("%lu\n", strlcpy(dst2, av[1], atoi(av[2])));
	printf("%s\n", dst2);
	}
	return (0);
}
/*#include <stdio.h>

int	main()
{
	char	source[] = "Hello, world!";
	char	destination[5];
	unsigned int 	k;
	
	k = ft_strlcpy(destination, source, 5);
	
	printf("Source string: %s\n", source);
	printf("Copied string: %s\n", destination);
	printf("Characters copied: %u\n", k);
	return (0);
}*/