/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:44:48 by zgoh              #+#    #+#             */
/*   Updated: 2023/11/03 21:07:04 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//count: number of elements to be allocated.M 
//size: size of each element, in bytes.

void	*ft_calloc(size_t count, size_t size)
{
	void	*idk;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	idk = (void *)malloc(count * size);
	if (!idk)
		return (NULL);
	ft_bzero(idk, count * size);
	return (idk);
}
/*
line 19: check whether value of count*size will overflow
line 27: set all bytes into 0
*/
