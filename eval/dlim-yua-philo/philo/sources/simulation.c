/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:01:08 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 19:01:09 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	begin_sim(t_table *table)
{
	unsigned int	i;

	table->sim_time_begin = current_time() + (table->num_philos * 2 * 10);
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&philosopher, table->philos[i]) != 0)
			return (error0("Thread creation error\n", table));
		i++;
	}
	if (table->num_philos > 1)
	{
		if (pthread_create(&table->death_bringer, NULL,
				&death_bringer, table) != 0)
			return (error0("Thread creation error\n", table));
	}
	return (true);
}

void	end_sim(t_table	*table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->num_philos > 1)
		pthread_join(table->death_bringer, NULL);
	destroy_mutexes(table);
	full_free(table);
}

void	destroy_mutexes(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->fork_lock[i]);
		pthread_mutex_destroy(&table->philos[i]->eat_lock);
		i++;
	}
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->end_sim_lock);
}

bool	has_sim_end(t_table *table)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&table->end_sim_lock);
	if (table->sim_end == true)
		r = true;
	pthread_mutex_unlock(&table->end_sim_lock);
	return (r);
}
