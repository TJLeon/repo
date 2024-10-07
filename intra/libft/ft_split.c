/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:01:41 by leotan            #+#    #+#             */
/*   Updated: 2023/11/11 01:05:21 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	w;
	int	t;

	i = 0;
	w = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] == c)
			t = 0;
		else if (t == 0)
		{
			w++;
			t = 1;
		}
		i++;
	}
	return (w);
}

static void	count_letter(char const *s, char c, char **arr)
{
	int	i;
	int	l;
	int	w;

	i = 0;
	l = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			l = 0;
		else
			l++;
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
		{
			arr[w] = ft_calloc(l + 1, sizeof(char));
			w++;
		}
		i++;
	}
	arr[w] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		l;
	int		w;

	if (!s)
		return (NULL);
	arr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	l = 0;
	w = 0;
	count_letter(s, c, arr);
	while (s[i])
	{
		if (s[i] == c)
			l = 0;
		else
			arr[w][l++] = s[i];
		if (s[i] != c && s[i + 1] == c)
			w++;
		i++;
	}
	return (arr);
}
/*#include <stdio.h>
void main()
{
	char *s = "      split       this for   me  !       ";

	char **result = ft_split(s, ' ');
	if (!result)
		printf("%s | S\n", result[0]);
	printf("%s | F\n", result[0]);
	printf("%s | F\n", result[1]);
	printf("%s | F\n", result[2]);
	printf("%s | F\n", result[3]);
	printf("%s | F\n", result[4]);
	printf("%s | F\n", result[5]);
}*/
