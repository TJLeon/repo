/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:41:16 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/09/07 17:41:17 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	unsigned int	num_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				full_eat_count;
	t_philo			**philos;
	bool			sim_end;
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	end_sim_lock;
	time_t			sim_time_begin;
	pthread_t		death_bringer;
}	t_table;

typedef struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	eat_lock;
	t_table			*table;
	unsigned int	eat_count;
	unsigned int	fork[2];
	pthread_t		thread;
	time_t			last_ate;
}	t_philo;

typedef enum e_status
{
	PHILO_DEAD = 0,
	PHILO_EAT = 1,
	PHILO_SLEEP = 2,
	PHILO_THINK = 3,
	PHILO_FORK_1ST = 4,
	PHILO_FORK_2ND = 5,
}	t_status;

bool			is_argv_valid(int argc, char **argv);
bool			check_digits(char *s);
int				ft_atoi(char *s);
t_table			*init_table(int argc, char **argv, int i);
t_philo			**init_philos(t_table *table);
void			place_forks(t_philo *philo);
bool			init_mutexplus(t_table *table);
pthread_mutex_t	*init_mutex_forks(t_table *table);
bool			begin_sim(t_table *table);
void			end_sim(t_table	*table);
void			destroy_mutexes(t_table *table);
bool			has_sim_end(t_table *table);
void			*philosopher(void *data);
void			*lonely(t_philo *philo);
void			philo_think(t_philo *philo, bool silent);
void			philo_eat_sleep(t_philo *philo);
void			*death_bringer(void *data);
bool			end_cond_reach(t_table *table);
bool			is_philo_dead(t_philo *philo);
void			set_sim_end(t_table *table, bool status);
time_t			current_time(void);
void			philo_pause(t_table *table, time_t pause_time);
void			sim_time_delay(time_t start_time);
int				print_msg(char *string, int exit_code);
void			*error_null(char *string, t_table *table);
int				error0(char *string, t_table *table);
void			*full_free(t_table *table);
void			print_status(t_philo *philo, bool death_bringer,
					t_status status);
void			ft_printf_status(t_philo *philo, char *string);

#endif
