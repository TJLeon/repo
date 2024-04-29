/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:08:33 by leotan            #+#    #+#             */
/*   Updated: 2024/04/25 12:26:06 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t t)
{
	void	*p;

	if (t != 0 && n > UINT32_MAX / t)
		return (NULL);
	p = malloc(n * t);
	if (p == NULL)
		return (p);
	return (ft_bzero(p, n * t), p);
}
