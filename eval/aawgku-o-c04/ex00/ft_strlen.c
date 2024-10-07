/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:51:19 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/09/26 14:57:57 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}


int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		printf("Total count is: %d\n", i);
	}
	return (0);
}
