/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:31:03 by mhamdan           #+#    #+#             */
/*   Updated: 2023/09/26 20:09:54 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d\n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
		printf("%d\n", strncmp(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
/*#include <stdlib.h>
int	main(int argc, char **argv)
{
	int	i;
	unsigned int	n;

	n = (unsigned int) (atoi(argv[3]));
	if (argc == 4)
	{
		i = ft_strncmp(argv[1], argv[2], n);
	}
	printf("value is: %d\n", i);
	return (0);
}*/
