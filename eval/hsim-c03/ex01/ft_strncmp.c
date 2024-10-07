/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:56:08 by hsim              #+#    #+#             */
/*   Updated: 2023/09/29 20:38:35 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' && i < n) || (s2[i] != '\0' && i < n))
	{
		if ((int)s1[i] == (int)s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	unsigned int	a;
	char 			s1[] = "banaizna";
	char 			s2[] = "bana";
	unsigned int	n;

	n = 6;
	a = ft_strncmp(s1, s2, n);
	printf("%d\n", a);
}
*/

/*
 compare string up to n
 */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		printf("%d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("%d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}