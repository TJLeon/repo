/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:35:45 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/18 17:03:44 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", ft_isdigit(d));
	printf("Below is the actual function's output\n");
	printf("%d\n",isdigit(c));
	printf("%d\n",isdigit(d));
	return (0);
}
*/
