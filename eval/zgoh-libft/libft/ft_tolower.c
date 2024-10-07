/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:43:35 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/18 17:03:46 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", tolower('A'));
	printf("%c\n", tolower('a'));
	printf("%c\n", ft_tolower('1'));
	printf("%c\n", tolower('1'));
	return (0);
}
*/
