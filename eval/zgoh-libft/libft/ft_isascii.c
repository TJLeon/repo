/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:52:32 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/18 17:03:44 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;
	char	d;

	c = 'z';
	d = '9';
	printf("%d\n", ft_isascii(c));
	printf("%d\n", ft_isascii(d));
	printf("Below is the actual function's output\n");
	printf("%d\n",isascii(c));
	printf("%d\n",isascii(d));
	return (0);
}
*/
