/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:16:37 by mhamdan           #+#    #+#             */
/*   Updated: 2023/09/26 20:21:51 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	counter;
	int	i;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		counter = 0;
		while (str[i] == to_find[i] && to_find[i] != '\0')
		{
			str++;
			to_find++;
			counter++;
		}
		if (to_find[i] == '\0')
		{
			return (str - counter);
		}
		str = str - counter + 1;
		to_find = to_find - counter;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	*result;

	result = ft_strstr(argv[1], argv[2]);
	if (argc == 3)
		result = ft_strstr(argv[1], argv[2]);
	if (result != NULL)
	{
		printf("Input: %s\n", argv[1]);
		printf("to find: %s\n", argv[2]);
		printf("result: %s\n", result);
	}
}*/
