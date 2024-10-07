/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:17:27 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 19:17:29 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	philo_pause(t_table *table, time_t pause_time)
{
	time_t	wake_up;

	wake_up = current_time() + pause_time;
	while (current_time() < wake_up)
	{
		if (has_sim_end(table))
			break ;
		usleep(100);
	}
}

void	sim_time_delay(time_t start_time)
{
	while (current_time() < start_time)
		continue ;
}
