/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:18:58 by zliow             #+#    #+#             */
/*   Updated: 2023/09/27 20:45:02 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char	destination[25] = "Hellooo";
	char	source[] = "magnificoooo";
	unsigned int	nb = 3;

	//printf("Orginal strncat: %s\n", strncat(destination, source, nb));
	printf("Ft_strncat result: %s\n", ft_strncat(destination, source, nb));
	
	return (0);
}*/
