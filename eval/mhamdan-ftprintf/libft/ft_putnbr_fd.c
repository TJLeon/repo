/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdan <mhamdan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:34:49 by mhamdan           #+#    #+#             */
/*   Updated: 2023/10/22 22:20:09 by mhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	digit;

	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		digit = (int)(nb) + '0';
	}
	else
	{
		digit = (int)(nb % 10) + '0';
		ft_putnbr_fd((int)(nb / 10), fd);
	}
	write(fd, &digit, 1);
}
