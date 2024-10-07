/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:55:43 by lkah-chu          #+#    #+#             */
/*   Updated: 2023/09/20 23:35:44 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		dest ++;
		src ++;
		n --;
		i++;
	}
	*dest = '\0';
	return (dest - i);
}
/*
#include <stdio.h>
int main(void)
{
    char src[] = "copythatlol";
    char dest[10];
    int n = 5;
    char *ptr_dest = ft_strncpy(dest, src, n);

    printf("%s\n", src);
    printf("%s\n", dest);
    printf("%s\n", ptr_dest);
    return(0);
}*/
