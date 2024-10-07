/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:49:54 by leotan            #+#    #+#             */
/*   Updated: 2024/09/23 03:50:17 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_valid_character(char *file)
{
	size_t	index;
	size_t	i_two;

	index = 0;
	while (file[index] != '\0')
	{
		i_two = 0;
		while ("01CEP\n"[i_two] != '\0' && file[index] != "01CEP\n"[i_two])
			i_two++;
		if ("01CEP\n"[i_two] == '\0')
			exit(write(2, "Error\nInvalid Map Character\n", 28));
		index++;
	}
}

void	map_valid_count(char *file)
{
	size_t	index;
	size_t	p_count;
	size_t	e_count;
	size_t	c_count;

	index = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (file[index] != '\0')
	{
		if (file[index] == 'P')
			p_count++;
		if (file[index] == 'E')
			e_count++;
		if (file[index] == 'C')
			c_count++;
		index++;
	}
	if (p_count != 1)
		exit(write(2, "Error\nWrong Amount Of P\n", 24));
	if (e_count != 1)
		exit(write(2, "Error\nWrong Amount Of E\n", 24));
	if (c_count < 1)
		exit(write(2, "Error\nWrong Amount Of C\n", 24));
}

void	map_valid_border(char **map)
{
	size_t	w_i;
	size_t	l_i;
	size_t	map_len;

	w_i = 0;
	map_len = get_map_length(map[0]);
	while (map[w_i] != NULL)
	{
		l_i = 0;
		while ((w_i == 0 || map[w_i + 1] == NULL) && map[w_i][l_i] == '1')
			l_i++;
		if (map[w_i][0] != '1' || map[w_i][map_len - 1] != '1')
			exit(write(2, "Error\nInvalid Map Border\n", 25));
		if ((w_i == 0 || map[w_i + 1] == NULL) && map[w_i][l_i] != '\0')
			exit(write(2, "Error\nInvalid Map Border\n", 25));
		w_i++;
	}
}
