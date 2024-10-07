/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:45:28 by mhamdan           #+#    #+#             */
/*   Updated: 2023/10/22 01:49:47 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	return (i >= '0' && i <= '9');
}

/*#include <stdio.h>
int	main(void)
{
	int i;

	i = 58;
	printf("%d\n", ft_isdigit(i));
	return (0);
}*/