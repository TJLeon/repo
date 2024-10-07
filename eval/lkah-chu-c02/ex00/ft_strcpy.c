/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:23:57 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 22:32:20 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		*dest = *src;
		dest ++;
		src ++;
		i ++;
	}
	*dest = '\0';
	return (dest - i);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "copythat";
	char dest[10];

	char *ptr_destination = ft_strcpy(dest, src);

	printf("%s\n", src);
	printf("%s\n", dest);
	printf("%s\n", ptr_destination);
	return(0);
}*/
