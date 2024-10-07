/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:14:46 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 17:14:48 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(int argc, char **argv, int i)
{
	t_table		*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (error_null("Memory allocation error\n", 0));
	table->num_philos = ft_atoi(argv[i++]);
	table->time_to_die = ft_atoi(argv[i++]);
	table->time_to_eat = ft_atoi(argv[i++]);
	table->time_to_sleep = ft_atoi(argv[i++]);
	table->full_eat_count = -1;
	if (argc - 1 == 5)
		table->full_eat_count = ft_atoi(argv[i]);
	table->philos = init_philos(table);
	if (!table->philos)
		return (NULL);
	if (!init_mutexplus(table))
		return (NULL);
	table->sim_end = false;
	return (table);
}

t_philo	**init_philos(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!philos)
		return (error_null("Memory allocation error\n", 0));
	i = 0;
	while (i < table->num_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (error_null("Memory allocation error\n", 0));
		philos[i]->id = i;
		if (pthread_mutex_init(&philos[i]->eat_lock, 0) != 0)
			return (error_null("Memory allocation error\n", 0));
		philos[i]->table = table;
		philos[i]->eat_count = 0;
		place_forks(philos[i]);
		i++;
	}
	return (philos);
}
