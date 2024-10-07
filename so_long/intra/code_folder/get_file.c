/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:40:31 by leotan            #+#    #+#             */
/*   Updated: 2024/09/24 21:50:57 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*extract_buffer(char *buffer, ssize_t byte, char *file)
{
	char	*temp;
	size_t	index;
	size_t	buffer_index;

	temp = ft_calloc(ft_strlen(file) + byte + 1, 1);
	if (temp == NULL)
		exit((perror("Error\nMemory"), 1));
	index = 0;
	while (file[index] != '\0')
	{
		temp[index] = file[index];
		index++;
	}
	buffer_index = 0;
	while (buffer_index < (size_t)byte)
		temp[index++] = buffer[buffer_index++];
	free(file);
	return (temp);
}

char	*get_file(int fd)
{
	char	*file;
	ssize_t	byte;
	char	buffer[64];

	file = ft_calloc(1, 1);
	if (file == NULL)
		exit((perror("Error\nMemory"), 1));
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buffer, 64);
		if (byte > 0)
			file = extract_buffer(buffer, byte, file);
		if (byte < 0)
			exit((perror("Error\nRead Function"), 1));
	}
	if (file[0] == '\0')
		exit(write(2, "Error\nEmpty Map File\n", 21));
	return (file);
}
