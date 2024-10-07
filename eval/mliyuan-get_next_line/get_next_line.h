/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:39:49 by mliyuan           #+#    #+#             */
/*   Updated: 2024/04/04 14:21:59 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

//linked list
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	get_buffer(int fd, t_list **lst);
void	add_to_lst(char *buffer, t_list **lst);
char	*return_line(t_list *lst);
void	clear_lst(t_list **lst);
int		ft_newline(t_list *lst);
int		ft_len_newline(t_list *lst);
void	dealloc(t_list **linked_list, t_list *clean_node, char *buffer);
void	append_str(t_list *lst, char *str);
t_list	*ft_lstlast(t_list *lst);

#endif
