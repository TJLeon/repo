/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:43:13 by mhamdan           #+#    #+#             */
/*   Updated: 2023/10/25 03:06:11 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimiter(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

static int	word_count(const char *str, char set)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && is_delimiter(str[i], set))
			i++;
		if (str[i] && !is_delimiter(str[i], set))
			word_count++;
		while (str[i] && !is_delimiter(str[i], set))
			i++;
	}
	return (word_count);
}

static char	*new_str(char const *str, char set)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str[i] && !is_delimiter(str[i], set))
		i++;
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (!newstr)
		return (0);
	i = 0;
	while (str[i] && !is_delimiter(str[i], set))
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char set)
{
	char	**split_str;
	int		count;
	int		i;

	if (!s)
		return (0);
	i = 0;
	count = word_count(s, set);
	split_str = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	while (*s)
	{
		while (*s && is_delimiter(*s, set))
			s++;
		if (*s)
		{
			split_str[i] = new_str(s, set);
			i++;
			while (*s && !is_delimiter(*s, set))
				s++;
		}
	}
	split_str[i] = 0;
	return (split_str);
}
