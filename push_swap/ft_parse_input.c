/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:19:57 by leotan            #+#    #+#             */
/*   Updated: 2024/09/08 15:59:13 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char **argv)
{
	int	i1;
	int	i2;
	int	word;
	int	pause;

	i1 = 0;
	word = 0;
	while (argv[++i1] != NULL)
	{
		pause = 0;
		i2 = -1;
		while (argv[i1][++i2] != '\0')
		{
			if (argv[i1][i2] == ' ')
				pause = 0;
			else if (pause == 0)
			{
				word++;
				pause = 1;
			}
		}
	}
	return (word);
}

static void	ft_count_letter(char **v, char **ptr)
{
	int	i;
	int	letter;
	int	word;
	int	x;

	i = 0;
	word = -1;
	while (v[++i] != NULL)
	{
		x = -1;
		letter = 0;
		while (v[i][++x] != '\0')
		{
			if (v[i][x] == ' ')
				letter = 0;
			else
				letter++;
			if (v[i][x] != ' ' && (v[i][x + 1] == ' ' || v[i][x + 1] == '\0'))
			{
				ptr[++word] = ft_calloc(letter + 1, 1);
				if (ptr[word] == NULL)
					ft_kill_switch((void **)ptr, NULL);
			}
		}
	}
}

static void	ft_filter(char **v, char **ptr)
{
	int	i;
	int	x;
	int	letter;
	int	word;

	i = 0;
	word = 0;
	while (v[++i] != NULL)
	{
		letter = 0;
		x = -1;
		while (v[i][++x] != '\0')
		{
			if (v[i][x] == ' ')
				letter = 0;
			else
				ptr[word][letter++] = v[i][x];
			if (v[i][x] != ' ' && (v[i][x + 1] == ' ' || v[i][x + 1] == '\0'))
				word++;
		}
	}
}

char	**ft_parse_input(char **argv)
{
	char	**ptr;

	ptr = ft_calloc(ft_count_word(argv) + 1, sizeof(char *));
	if (ptr == NULL)
		ft_kill_switch(NULL, NULL);
	ft_count_letter(argv, ptr);
	ft_filter(argv, ptr);
	return (ptr);
}
