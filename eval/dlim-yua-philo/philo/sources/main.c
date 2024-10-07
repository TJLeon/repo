/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:53:20 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 15:53:22 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc - 1 < 4 || argc - 1 > 5)
		return (print_msg("Incorrect number of arguments\n", EXIT_FAILURE));
	if (!is_argv_valid(argc, argv))
		return (EXIT_FAILURE);
	table = init_table(argc, argv, 1);
	if (!table)
		return (EXIT_FAILURE);
	if (!begin_sim(table))
		return (EXIT_FAILURE);
	end_sim(table);
	return (EXIT_SUCCESS);
}

void	print_status(t_philo *philo, bool death_bringer, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (has_sim_end(philo->table) == true && death_bringer == false)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	if (status == PHILO_DEAD)
		ft_printf_status(philo, "died");
	else if (status == PHILO_EAT)
		ft_printf_status(philo, "is eating");
	else if (status == PHILO_SLEEP)
		ft_printf_status(philo, "is sleeping");
	else if (status == PHILO_THINK)
		ft_printf_status(philo, "is thinking");
	else if (status == PHILO_FORK_1ST || status == PHILO_FORK_2ND)
		ft_printf_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	ft_printf_status(t_philo *philo, char *string)
{
	printf("%ld %d %s\n", current_time() - philo->table->sim_time_begin,
		philo->id + 1, string);
}
