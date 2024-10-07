/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:38:07 by zliow             #+#    #+#             */
/*   Updated: 2023/09/21 23:05:33 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char	destination[] = "Why does evolution work the work it work?";
	char	source[] = "Percentages of chance!";

	printf("Original destination string: %s\n", destination);
	printf("Source string: %s\n", source);
	ft_strncpy(destination, source, 6);
	printf("Copied destination string: %s\n", destination);

	return (0);
}*/
