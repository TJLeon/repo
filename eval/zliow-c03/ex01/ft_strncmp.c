/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:25:03 by zliow             #+#    #+#             */
/*   Updated: 2023/10/05 14:44:50 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	unsigned int	n;

	n = 3;
	if (argc == 3)
	{
		printf("Original strncmp: %d\n", strncmp(argv[1], argv[2], n));
		printf("Ft_strncmp result: %d\n", ft_strncmp(argv[1], argv[2], n));
	}
	return (0);
}*/
