/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:08:33 by leotan            #+#    #+#             */
/*   Updated: 2024/03/17 21:44:27 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t t)
{
	void	*ptr;

	if (t != 0 && n > UINT_MAX / t)
		return (NULL);
	ptr = malloc(n * t);
	if (ptr)
		ft_bzero(ptr, n * t);
	return (ptr);
}
