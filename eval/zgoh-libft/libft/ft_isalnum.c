/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:18:25 by zgoh              #+#    #+#             */
/*   Updated: 2023/10/18 17:03:42 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	c;
	char	d;
	char	e;

	c = 'z';
	d = '9';
	e = '$';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", ft_isalnum(e));
	printf("Below is the actual function's output\n");
	printf("%d\n",isalnum(c));
	printf("%d\n",isalnum(d));
	printf("%d\n",isalnum(e));
	return (0);
}
*/
