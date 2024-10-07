/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:04:44 by liyu-her          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:37 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	dest[i++] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char				dest1[50] = "bonjour";
	char				dest2[50] = "bonjour";
	char				*src;
	unsigned int		size;

	size = 5;
	src = " les amis";
	printf(".%s.\n", strncat(dest1, src, size));
	printf(".%s.\n", ft_strncat(dest2, src, size));
}
*/
