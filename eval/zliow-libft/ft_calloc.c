/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zliow < zliow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:14:51 by zliow             #+#    #+#             */
/*   Updated: 2023/12/24 06:09:33 by zliow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((size != 0 && count > UINT_MAX / size) || (count != 0 && size > UINT_MAX
			/ count))
	{
		return (0);
	}
	ptr = (void *)malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	else
	{
		ft_bzero(ptr, count * size);
	}
	return (ptr);
}
