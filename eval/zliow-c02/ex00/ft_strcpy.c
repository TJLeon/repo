/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:54:45 by zliow             #+#    #+#             */
/*   Updated: 2023/09/20 21:41:41 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

/*#include <stdio.h>

int	main()
{
	char source[] = "Hello, beautiful world and beings!";
	char destination[] = "Goodbye, dark and moody world.";
	
	printf("Source string: %s\n", source);
	printf("Original destination string: %s\n", destination);
	printf("Copied destination string: %s\n", ft_strcpy(destination, source));

	return (0);
}*/
