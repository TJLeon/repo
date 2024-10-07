/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:30:53 by mhamdan           #+#    #+#             */
/*   Updated: 2023/09/21 17:28:20 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = ft_strcmp(argv[1], argv[2]);
	}
	printf ("Value is: %d\n", i);
	return (0);
}*/
