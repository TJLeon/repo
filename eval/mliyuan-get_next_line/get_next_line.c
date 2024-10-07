/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:20:01 by mliyuan           #+#    #+#             */
/*   Updated: 2024/04/11 12:37:03 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list		*lst = NULL;
	char				*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	get_buffer(fd, &lst);
	if (lst == NULL)
		return (NULL);
	buffer = return_line(lst);
	clear_lst(&lst);
	return (buffer);
}

void	get_buffer(int fd, t_list **lst)
{
	int		readed_characters;
	char	*buffer;

	while (ft_newline(*lst) != 1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		readed_characters = read(fd, buffer, BUFFER_SIZE);
		if (readed_characters == 0)
		{
			free(buffer);
			return ;
		}
		buffer[readed_characters] = '\0';
		add_to_lst(buffer, lst);
	}
}

void	add_to_lst(char *buffer, t_list **lst)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

char	*return_line(t_list *lst)
{
	int		len;
	char	*str;

	if (lst == NULL)
		return (NULL);
	len = ft_len_newline(lst);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	append_str(lst, str);
	return (str);
}

void	clear_lst(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list));
	if (clean_node == NULL || buffer == NULL)
		return ;
	last_node = ft_lstlast(*lst);
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] != '\0')
		buffer[j++] = last_node->content[++i];
	buffer[j] = '\0';
	clean_node->content = buffer;
	clean_node->next = NULL;
	dealloc(lst, clean_node, buffer);
}
