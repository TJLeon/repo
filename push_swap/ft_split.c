/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:19:57 by leotan            #+#    #+#             */
/*   Updated: 2024/09/02 16:33:57 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char **argv)
{
	unsigned long long	i;
	unsigned long long	x;
	unsigned long long	w;
	int					t;

	i = 0;
	w = 0;
	while (argv[++i] != NULL)
	{
		t = 0;
		x = -1;
		while (argv[i][++x] != '\0')
		{
			if (argv[i][x] == ' ')
				t = 0;
			else if (t == 0)
			{
				w++;
				t = 1;
			}
		}
	}
	return (w);
}

static void	ft_count_letter(char **v, char **arr)
{
	unsigned long long	i;
	unsigned long long	l;
	unsigned long long	w;
	unsigned long long	x;

	i = 0;
	w = -1;
	while (v[++i] != NULL)
	{
		x = -1;
		l = 0;
		while (v[i][++x])
		{
			if (v[i][x] == ' ')
				l = 0;
			else
				l++;
			if (v[i][x] != ' ' && (v[i][x + 1] == ' ' || v[i][x + 1] == '\0'))
			{
				arr[++w] = ft_calloc(l + 1, 1);
				if (arr[w] == NULL)
					exit((ft_free_2d_arr(arr), write(2, "Error\n", 6)));
			}
		}
	}
}

static void	ft_fill_arr(char **v, char **arr)
{
	unsigned long long	i;
	unsigned long long	x;
	unsigned long long	l;
	unsigned long long	w;

	i = 0;
	w = 0;
	while (v[++i] != NULL)
	{
		l = 0;
		x = -1;
		while (v[i][++x] != '\0')
		{
			if (v[i][x] == ' ')
				l = 0;
			else
				arr[w][l++] = v[i][x];
			if (v[i][x] != ' ' && (v[i][x + 1] == ' ' || v[i][x + 1] == '\0'))
				w++;
		}
	}
}

char	**ft_split(char **argv)
{
	char	**arr;

	if (argv == NULL)
		return (NULL);
	arr = ft_calloc(ft_count_word(argv) + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	ft_count_letter(argv, arr);
	ft_fill_arr(argv, arr);
	return (arr);
}
