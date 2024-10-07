/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:03:07 by mhamdan           #+#    #+#             */
/*   Updated: 2023/09/26 20:35:51 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count_dest;
	unsigned int	count_src;

	count_dest = 0;
	count_src = 0;
	while (dest[count_dest] != '\0')
	{
		count_dest++;
	}
	while ((src[count_src] != '\0') && (count_src < size))
	{
		dest[count_dest + count_src] = src[count_src];
		count_src++;
	}
	dest[count_dest + count_src] = '\0';
	return (count_dest + count_src);
}

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
int	main(int ac, char **av)
{
	char dst1[11] = "hello";
	char dst2[11] = "hello";
	if (ac == 3)
	{
	printf("%u\n", ft_strlcat(dst1, av[1], atoi(av[2])));
	printf("%s\n", dst1);
	printf("%lu\n", strlcat(dst2, av[1], atoi(av[2])));
	printf("%s\n", dst2);
	}
	return (0);
}
/*#include <stdlib.h>
int main(int argc, char **argv)
{
    unsigned int    size;ii

    size = (unsigned int) (atoi(argv[3]));
    if (argc == 4)
    {
        printf("result is: %u\n", ft_strlcat(argv[1], argv[2], size));
        printf("%s \n",argv[1]);
    }
    return (0);
}*/
