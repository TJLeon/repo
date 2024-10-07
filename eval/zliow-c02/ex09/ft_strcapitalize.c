/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow <zliow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:53:49 by zliow             #+#    #+#             */
/*   Updated: 2023/09/22 23:46:05 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_upcase(char letter)
{
	if (letter >= 'a' && letter <= 'z')
	{
		letter -= 32;
	}
	return (letter);
}

char	ft_lowcase(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
	letter += 32;
	}
	return (letter);
}

int	is_alphabet(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize;

	i = 0;
	capitalize = 1;
	while (str[i] != '\0')
	{
		if (isAlphabet(str[i]))
		{
			if (capitalize == 1)
			{
				str[i] = ft_upcase(str[i]);
				capitalize = 0;
			}
			else
				str[i] = ft_lowcase(str[i]);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			capitalize = 0;
		else
			capitalize = 1;
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_strcapitalize(argv[1]);
		printf("%s\n", argv[1]);
	}
	return (0);
}
