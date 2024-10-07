/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 03:34:00 by leotan            #+#    #+#             */
/*   Updated: 2024/09/23 03:34:40 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t len, size_t byte)
{
	void	*ptr;

	ptr = malloc(len * byte);
	if (ptr != NULL)
		ft_bzero(ptr, len * byte);
	return (ptr);
}
