/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:45:50 by lybey             #+#    #+#             */
/*   Updated: 2024/09/08 20:02:23 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	size_t			last_meal;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	int				meals;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nbr_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	int				nbr_meals;
	int				philo_death;
	size_t			start_time;
	int				all_ate;
	pthread_mutex_t	all_ate_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	print_msg;
	pthread_mutex_t	last_meal_lock;
	t_philo			*philos;
}					t_data;

//PARSING
int					ft_atoi(char *str);
int					is_digit(char *argv);
int					init_data(t_data *data, int ac, char **av);
int					ft_not_number(int ac, char **av);
//ROUTINE
void				*routine(void *ptr);
int					eating(t_philo *philo);
int					routine_odd(t_philo *philo);
int					routine_even(t_philo *philo);
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				create_one_philo(t_philo *philo);
void				*routine_one_philo(void *pointer);
//INIT
int					create_philo(t_data *data, t_philo *philos);
void				init_forks(t_data *data, t_philo *philo);
// void				init_philo(t_data *data, t_philo *philo);
int					ft_init_mutex(t_data *data);
void				ft_destroy(t_data *data, t_philo *philo);
// UTILS

int					print_msg(char *msg, t_philo *philo);
void				ft_usleep(size_t time_sleep);
size_t				get_time(void);
void				wait_philo(t_data *data, t_philo *philo);

// monitoring
int					dead_is_dead(t_philo *philo);
int					check_if_dead(t_philo *philo, size_t time_to_die);
int					update_all_ate(t_philo *philo);
int					check_if_all_ate(t_philo *philo);
int					monitoring(t_philo *philo);

#endif
