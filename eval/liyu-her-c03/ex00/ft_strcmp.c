/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:09:11 by liyu-her          #+#    #+#             */
/*   Updated: 2023/09/28 00:21:49 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>
int		main(void)
{
	char	*str1;
	char	*str2;

	str1 = "adwwafwDWQfww";
	str2 = "adwwafwDWQfw";
	printf("Mimic fuction: %d\n", ft_strcmp(str1, str2));i
	printf("Ori fuction: %d\n", strcmp(str1, str2));
}
*/
