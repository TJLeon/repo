/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmal <tdharmal@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:30:05 by tdharmal          #+#    #+#             */
/*   Updated: 2023/10/04 22:58:17 by tdharmal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		while (*argv[0])
		{
			ft_putchar(*argv[0]);
			argv[0]++;
		}
		ft_putchar('\n');
	}
	return (0);
}
