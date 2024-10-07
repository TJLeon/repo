/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose <ajose@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:31:35 by ajose             #+#    #+#             */
/*   Updated: 2024/07/21 23:32:38 by ajose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bytelevelb;

	bytelevelb = b;
	while (len--)
	{
		*bytelevelb++ = (unsigned char) c;
	}
	return (b);
}
