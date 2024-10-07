/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:38:56 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 16:38:58 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_argv_valid(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!check_digits(argv[i]))
			return (print_msg("Positive integers only\n", false));
		num = ft_atoi(argv[i]);
		if (i == 1 && (num <= 0 || num > 200))
			return (print_msg("Invalid number of philosophers\n", false));
		if (i != 1 && num == -1)
			return (print_msg("Positive integers only\n", false));
		i++;
	}
	return (true);
}

bool	check_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(char *s)
{
	unsigned long long int	num;
	int						i;

	i = 0;
	num = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	if (num > INT_MAX)
		return (-1);
	return ((int)num);
}
