/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfield.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:51:11 by leotan            #+#    #+#             */
/*   Updated: 2024/09/24 22:07:18 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fieldflooding(char **map, size_t w_i, size_t l_i)
{
	map[w_i][l_i] = '-';
	if (map[w_i - 1][l_i] != '1' && map[w_i - 1][l_i] != '-')
		fieldflooding(map, w_i - 1, l_i);
	if (map[w_i][l_i - 1] != '1' && map[w_i][l_i - 1] != '-')
		fieldflooding(map, w_i, l_i - 1);
	if (map[w_i][l_i + 1] != '1' && map[w_i][l_i + 1] != '-')
		fieldflooding(map, w_i, l_i + 1);
	if (map[w_i + 1][l_i] != '1' && map[w_i + 1][l_i] != '-')
		fieldflooding(map, w_i + 1, l_i);
}

static void	unreachable_check(char **map)
{
	size_t	w_i;
	size_t	l_i;

	w_i = 1;
	while (map[w_i] != NULL)
	{
		l_i = 1;
		while (map[w_i][l_i] != '\0')
		{
			if (map[w_i][l_i] == 'C')
				exit(write(2, "Error\nUnreachable Collectable\n", 30));
			if (map[w_i][l_i] == 'E')
				exit(write(2, "Error\nUnreachable Exit\n", 23));
			l_i++;
		}
		w_i++;
	}
}

void	floodfield(char **map)
{
	size_t	w_i;
	size_t	l_i;

	w_i = 1;
	while (map[w_i] != NULL)
	{
		l_i = 1;
		while (map[w_i][l_i] != '\0')
		{
			if (map[w_i][l_i] == 'P')
				fieldflooding(map, w_i, l_i);
			l_i++;
		}
		w_i++;
	}
	unreachable_check(map);
	w_i = 0;
	while (map[w_i] != NULL)
		free(map[w_i++]);
	free(map);
}
