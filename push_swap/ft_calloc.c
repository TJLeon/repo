/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:22:40 by leotan            #+#    #+#             */
/*   Updated: 2024/09/05 20:40:19 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t size, size_t byte)
{
	void	*ptr;

	ptr = malloc(size * byte);
	if (ptr != NULL)
		ft_bzero(ptr, size * byte);
	return (ptr);
}
