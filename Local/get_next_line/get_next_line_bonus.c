/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:16:53 by leotan            #+#    #+#             */
/*   Updated: 2024/04/02 20:16:05 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	extract_sline(char **rline, char **sline)
{
	unsigned long long	x;

	x = -1;
	*rline = malloc(ft_strlen(*sline) + 1);
	while ((*sline)[++x] != '\0')
		(*rline)[x] = (*sline)[x];
	(*rline)[x] = (*sline)[x];
	free(*sline);
	*sline = NULL;
	return (42);
}

static int	extract_buff(ssize_t n, char **rline, char **sline, char *buff)
{
	unsigned long long	x;
	char				*tmp;
	long long			z;

	x = -1;
	tmp = NULL;
	z = 0;
	if (n > 0)
	{
		tmp = malloc(ft_strlen(*sline) + n + 1);
		if (tmp == NULL)
			return (0);
		while ((*sline)[++x] != '\0')
			tmp[x] = (*sline)[x];
		while (z < n)
			tmp[x++] = buff[z++];
		tmp[x] = '\0';
		free(*sline);
		*sline = tmp;
		tmp = NULL;
		return (42);
	}
	return (extract_sline(rline, sline));
}

static int	extract_newline(char **rline, char **sline)
{
	unsigned long long	x;
	char				*tmp;
	long long			z;

	x = -1;
	tmp = NULL;
	z = 0;
	while ((*sline)[++x] != '\n')
		(*rline)[x] = (*sline)[x];
	(*rline)[x] = (*sline)[x];
	(*rline)[++x] = '\0';
	tmp = malloc(ft_strlen(&(*sline)[x]) + 1);
	if (tmp == NULL)
	{
		free(*rline);
		*rline = NULL;
		return (0);
	}
	while ((*sline)[x] != '\0')
		tmp[z++] = (*sline)[x++];
	tmp[z] = (*sline)[x];
	free(*sline);
	*sline = tmp;
	tmp = NULL;
	return (42);
}

static int	ft_extract(char **rline, char **sline, int fd, unsigned long long i)
{
	ssize_t	bytes_read;
	char	buff[BUFFER_SIZE];

	if ((*sline)[i] == '\n')
	{
		*rline = malloc(i + 2);
		if (*rline == NULL)
			return (0);
		return (extract_newline(rline, sline));
	}
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 1 && (*sline)[0] == '\0')
	{
		free(*sline);
		*sline = NULL;
		return (0);
	}
	return (extract_buff(bytes_read, rline, sline, buff));
}

char	*get_next_line(int fd)
{
	static char			*saved[OPEN_MAX];
	unsigned long long	i;
	char				*return_line;

	i = 0;
	return_line = NULL;
	if (fd < 0)
		return (NULL);
	if (saved[fd] == NULL)
	{
		saved[fd] = malloc(sizeof(char));
		if (saved[fd] == NULL)
			return (NULL);
		saved[fd][0] = '\0';
	}
	while (return_line == NULL)
	{
		while (saved[fd][i] != '\n' && saved[fd][i] != '\0')
			i++;
		if (saved[fd][i] == '\n')
			return (ft_extract(&return_line, &saved[fd], fd, i), return_line);
		else if (ft_extract(&return_line, &saved[fd], fd, i) < 1)
			return (return_line);
	}
	return (return_line);
}
