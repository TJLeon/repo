/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:56:42 by liyu-her          #+#    #+#             */
/*   Updated: 2023/09/28 00:23:20 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	dest1[50] = "bonjour";
	char	dest2[50] = "bonjour";
	char	*src1;
	char	*src2;

	src1 = " les amis";
	src2 = " les amis";
	printf(".%s.\n", ft_strcat(dest1, src1));
	printf(".%s.\n", strcat(dest2, src2));
}
*/
