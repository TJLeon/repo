/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bringer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:16:16 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 22:16:17 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_bringer(void *data)
{
	t_table		*table;

	table = (t_table *)data;
	if (table->full_eat_count == 0)
		return (NULL);
	set_sim_end(table, false);
	sim_time_delay(table->sim_time_begin);
	while (true)
	{
		if (end_cond_reach(table) == true)
			return (NULL);
		usleep (1000);
	}
	return (NULL);
}

bool	end_cond_reach(t_table *table)
{
	unsigned int	i;
	bool			all_philo_full;

	all_philo_full = true;
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->philos[i]->eat_lock);
		if (is_philo_dead(table->philos[i]))
			return (true);
		if (table->full_eat_count != -1)
			if (table->philos[i]->eat_count
				< (unsigned int)table->full_eat_count)
				all_philo_full = false;
		pthread_mutex_unlock(&table->philos[i]->eat_lock);
		i++;
	}
	if (table->full_eat_count != -1 && all_philo_full == true)
	{
		set_sim_end(table, true);
		return (true);
	}
	return (false);
}

bool	is_philo_dead(t_philo *philo)
{
	time_t	time;

	time = current_time();
	if ((time - philo->last_ate) >= philo->table->time_to_die)
	{
		set_sim_end(philo->table, true);
		print_status(philo, true, PHILO_DEAD);
		pthread_mutex_unlock(&philo->eat_lock);
		return (true);
	}
	return (false);
}

void	set_sim_end(t_table *table, bool status)
{
	pthread_mutex_lock(&table->end_sim_lock);
	table->sim_end = status;
	pthread_mutex_unlock(&table->end_sim_lock);
}
