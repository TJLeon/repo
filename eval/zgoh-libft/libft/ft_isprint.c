/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:19:17 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/22 04:24:13 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
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
	printf("%d\n", ft_isprint(c));
	printf("%d\n", ft_isprint(d));
	printf("Below is the actual function's output\n");
	printf("%d\n",isprint(c));
	printf("%d\n",isprint(d));

	printf("%d\n",ft_isprint(127));
	printf("%d\n",isprint(127));

	return (0);
}
*/
