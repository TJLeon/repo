/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:48:07 by leotan            #+#    #+#             */
/*   Updated: 2024/09/23 03:48:32 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map(char *file, char **map, size_t map_width)
{
	size_t	width_index;
	size_t	file_index;
	size_t	len_index;
	size_t	map_len;

	width_index = 0;
	file_index = 0;
	map_len = get_map_length(file);
	while (width_index < map_width)
	{
		len_index = 0;
		map[width_index] = ft_calloc(map_len + 1, 1);
		if (map[width_index] == NULL)
			exit((perror("Error\nMemory"), 1));
		while (file[file_index] != '\0' && file[file_index] != '\n')
			map[width_index][len_index++] = file[file_index++];
		if (len_index != map_len)
			exit(write(2, "Error\nMap Not Rectangular\n", 26));
		if (file[file_index] == '\n')
			file_index++;
		width_index++;
	}
}

char	**file_to_map(char *file)
{
	size_t	map_width;
	char	**map;

	map_width = get_map_width(file);
	map = ft_calloc(map_width + 1, sizeof(char *));
	if (map == NULL)
		exit((perror("Error\nMemory"), 1));
	fill_map(file, map, map_width);
	return (map);
}
