/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:33:33 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 16:33:35 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(char *string, int exit_code)
{
	printf("%s", string);
	return (exit_code);
}

void	*error_null(char *string, t_table *table)
{
	if (table != NULL)
		full_free(table);
	print_msg(string, EXIT_FAILURE);
	return (NULL);
}

int	error0(char *string, t_table *table)
{
	if (table != NULL)
		full_free(table);
	return (print_msg(string, 0));
}

void	*full_free(t_table *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->fork_lock != NULL)
		free(table->fork_lock);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}
