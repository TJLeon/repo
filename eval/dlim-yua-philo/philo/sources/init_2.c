/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:15:01 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 17:15:02 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	place_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->num_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->num_philos;
		philo->fork[1] = philo->id;
	}
}

bool	init_mutexplus(t_table *table)
{
	table->fork_lock = init_mutex_forks(table);
	if (!table->fork_lock)
		return (false);
	if (pthread_mutex_init(&table->print_lock, 0) != 0)
		return (error0("Mutex creation error\n", table));
	if (pthread_mutex_init(&table->end_sim_lock, 0) != 0)
		return (error0("Mutex creation error\n", table));
	return (true);
}

pthread_mutex_t	*init_mutex_forks(t_table *table)
{
	pthread_mutex_t		*forks;
	unsigned int		i;

	forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!forks)
		return (error_null("Memory allocation error\n", 0));
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null("Mutex creation error\n", 0));
		i++;
	}
	return (forks);
}
