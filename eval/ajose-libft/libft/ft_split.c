/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose <ajose@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:32:04 by ajose             #+#    #+#             */
/*   Updated: 2024/07/21 23:32:29 by ajose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*create_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**fill_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		split[i] = create_word(s, word_len);
		if (!split[i])
			return (free_all(split, i));
		s += word_len;
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_cnt;

	if (!s)
		return (NULL);
	word_cnt = word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!split)
		return (NULL);
	return (fill_split(s, c, split));
}
