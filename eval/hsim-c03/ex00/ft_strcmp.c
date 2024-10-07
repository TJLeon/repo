/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:55:37 by hsim              #+#    #+#             */
/*   Updated: 2023/09/29 20:46:29 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	//int a;
	printf("%d\n", strcmp("0", ""));
	//a = ft_strcmp("babana","babana");
	//printf("%d\n", a);
}*/
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", ft_strcmp(argv[1], argv[2]));
		printf("%d\n", strcmp("0", ""));
	}
	return (0);
}

