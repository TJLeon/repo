/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:59:32 by zgoh              #+#    #+#             */
/*   Updated: 2024/03/17 19:57:07 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//count_word used to count how many word in the string s
//flag = 1, indicate is pointing to a word
//i is the counter
static int	count_word(const char *s, char c)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			++i;
		}
		else if (*s == c && flag == 1)
			flag = 0;
		++s;
	}
	return (i);
}

//return (word-len)
//	>so *word will point to the first character again
static char	*dup_word(const char *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i++ < len)
		*(word++) = *(s++);
	*word = '\0';
	return (word - len);
}

char	**split_word(char **final, const char *s, char c)
{
	int	z;
	int	len;
	int	num_w;

	z = 0;
	len = 0;
	num_w = count_word(s, c);
	while (z < num_w && *s)
	{
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		final[z++] = dup_word(s - len, len);
		len = 0;
	}
	final[z] = NULL;
	return (final);
}

//if say we have 8 words, then we will have 8 *final and 1 *final point to \0
char	**ft_split(char const *s, char c)
{
	char	**final;

	if (!s)
		return (NULL);
	final = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!final)
		return (NULL);
	final = split_word(final, s, c);
	return (final);
}
/*
int	main(void)
{
	//char **test = ft_split("                  olol",' ');
	//char **test = ft_split("olol                     ",' ');
	//char **test = ft_split("split  ||this|for|me|||||!|",'|');
	//char **test = ft_split("      split       this for   me  !       ",' ');
	//char **test = ft_split("          ", ' '); 
	char **test = ft_split("   lorem   ipsum dolor     sit amet, consectetur
	   adipiscing elit. Sed non risus. Suspendisse   ", ' ');

	for (int i = 0; i <= count_w("   lorem   ipsum dolor     sit amet,
	 consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' '); ++i)
		printf("%s\n",test[i]);
	return (0);
}
*/
