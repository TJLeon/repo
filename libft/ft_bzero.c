/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:49:37 by leotan            #+#    #+#             */
/*   Updated: 2023/10/26 21:56:21 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	a = s;
	i = 0;
	while (i < n)
		a[i++] = 0;
}
