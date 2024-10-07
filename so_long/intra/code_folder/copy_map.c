/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:51:14 by leotan            #+#    #+#             */
/*   Updated: 2024/09/23 03:51:41 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map_size(char **map)
{
	size_t	index;
	char	**copy;
	size_t	map_width;

	index = 0;
	while (map[index] != NULL)
		index++;
	map_width = index;
	copy = ft_calloc(map_width + 1, sizeof(char *));
	if (copy == NULL)
		exit((perror("Error\nMemory"), 1));
	index = 0;
	while (index < map_width)
	{
		copy[index] = ft_calloc(get_map_length(map[0]) + 1, 1);
		if (copy[index++] == NULL)
			exit((perror("Error\nMemory"), 1));
	}
	return (copy);
}

char	**copy_map(char **map)
{
	char	**copy;
	size_t	width_index;
	size_t	len_index;

	copy = copy_map_size(map);
	width_index = 0;
	while (map[width_index] != NULL)
	{
		len_index = 0;
		while (map[width_index][len_index] != '\0')
		{
			copy[width_index][len_index] = map[width_index][len_index];
			len_index++;
		}
		width_index++;
	}
	return (copy);
}
