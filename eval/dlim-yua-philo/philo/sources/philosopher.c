/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:25:40 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 19:25:43 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->full_eat_count == 0)
		return (NULL);
	pthread_mutex_lock(&philo->eat_lock);
	philo->last_ate = philo->table->sim_time_begin;
	pthread_mutex_unlock(&philo->eat_lock);
	sim_time_delay(philo->table->sim_time_begin);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->num_philos == 1)
		return (lonely(philo));
	else if (philo->id % 2)
		philo_think(philo, true);
	while (has_sim_end(philo->table) == false)
	{
		philo_eat_sleep(philo);
		philo_think(philo, false);
	}
	return (NULL);
}

void	*lonely(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[0]]);
	print_status(philo, false, PHILO_FORK_1ST);
	philo_pause(philo->table, philo->table->time_to_die);
	print_status(philo, false, PHILO_DEAD);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[0]]);
	return (NULL);
}

void	philo_think(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->eat_lock);
	time_to_think = (philo->table->time_to_die
			- (current_time() - philo->last_ate)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->eat_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == false)
		print_status(philo, false, PHILO_THINK);
	philo_pause(philo->table, time_to_think);
}

void	philo_eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[0]]);
	print_status(philo, false, PHILO_FORK_1ST);
	pthread_mutex_lock(&philo->table->fork_lock[philo->fork[1]]);
	print_status(philo, false, PHILO_FORK_2ND);
	print_status(philo, false, PHILO_EAT);
	pthread_mutex_lock(&philo->eat_lock);
	philo->last_ate = current_time();
	pthread_mutex_unlock(&philo->eat_lock);
	philo_pause(philo->table, philo->table->time_to_eat);
	if (has_sim_end(philo->table) == false)
	{
		pthread_mutex_lock(&philo->eat_lock);
		philo->eat_count += 1;
		pthread_mutex_unlock(&philo->eat_lock);
	}
	print_status(philo, false, PHILO_SLEEP);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->fork[0]]);
	philo_pause(philo->table, philo->table->time_to_sleep);
}
