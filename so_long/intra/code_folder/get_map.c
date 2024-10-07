/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:43:23 by leotan            #+#    #+#             */
/*   Updated: 2024/09/25 12:09:30 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_map_width(char *file)
{
	size_t	index;
	size_t	map_width;

	index = 0;
	map_width = 1;
	while (file[index] != '\0')
	{
		if (file[index + 1] != '\0' && file[index] == '\n')
			map_width++;
		index++;
	}
	if (map_width < 3)
		exit(write(2, "Error\nMap Width Too Small\n", 26));
	return (map_width);
}

size_t	get_map_length(char *file)
{
	size_t	index;
	size_t	length;

	index = 0;
	while (file[index] != '\0' && file[index] != '\n')
		index++;
	length = index;
	return (length);
}

char	**get_map(int fd)
{
	char	*file;
	char	**map;

	file = get_file(fd);
	map_valid_character(file);
	map_valid_count(file);
	map = file_to_map(file);
	free(file);
	map_valid_border(map);
	floodfield(copy_map(map));
	return (map);
}

size_t	get_map_c_total(char **map)
{
	size_t	w_i;
	size_t	l_i;
	size_t	c_count;

	w_i = 1;
	c_count = 0;
	while (map[w_i] != NULL)
	{
		l_i = 1;
		while (map[w_i][l_i] != '\0')
		{
			if (map[w_i][l_i] == 'C')
				c_count++;
			l_i++;
		}
		w_i++;
	}
	return (c_count);
}

void	get_map_pos(t_game *game)
{
	size_t	w_i;
	size_t	l_i;

	w_i = 1;
	while (game->map[w_i] != NULL)
	{
		l_i = 1;
		while (game->map[w_i][l_i] != '\0')
		{
			if (game->map[w_i][l_i] == 'P')
			{
				game->p_w = w_i;
				game->p_l = l_i;
			}
			if (game->map[w_i][l_i] == 'E')
			{
				game->e_w = w_i;
				game->e_l = l_i;
			}
			l_i++;
		}
		w_i++;
	}
}
