/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:47:31 by mhamdan           #+#    #+#             */
/*   Updated: 2023/09/26 20:16:06 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_count;
	int	src_count;

	dest_count = 0;
	src_count = 0;
	while (dest[dest_count] != '\0' )
		dest_count++;
	while (src[src_count] != '\0' && src_count < nb)
	{
		dest[dest_count] = src[src_count];
		dest_count++;
		src_count++;
	}
	dest[dest_count] = '\0';
	return (dest);
}

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    unsigned int    nb;

    nb = (unsigned int) (atoi(argv[3]));

    if (argc == 4)
        printf("concatenated string: %s\n", ft_strncat(argv[1], argv[2], nb));
    return (0);
}
