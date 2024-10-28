/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:48:17 by lybey             #+#    #+#             */
/*   Updated: 2024/09/10 12:19:21 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		pthread_mutex_init(&philo[i].fork_l, NULL);
		if (i == data->nbr_philo - 1)
			philo[i].fork_r = &philo[0].fork_l;
		else
			philo[i].fork_r = &philo[i + 1].fork_l;
		philo[i].meals = 0;
		philo[i].last_meal = get_time();
		i++;
	}
}

// Fonctions qui sert a creer les threads pour chaque philo et faire la routine
int	create_philo(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
		{
			return (printf("erreur_create_philo\n"), 1);
		}
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_msg, NULL) != 0)
		return ((printf("Failed to initialize mutex\n")), 1);
	if (pthread_mutex_init(&data->all_ate_lock, NULL) != 0)
		return ((printf("Failed to initialize mutex\n")), 1);
	if (pthread_mutex_init(&data->meals_lock, NULL) != 0)
		return ((printf("Failed to initialize mutex\n")), 1);
	if (pthread_mutex_init(&data->last_meal_lock, NULL) != 0)
		return ((printf("Failed to initialize mutex\n")), 1);
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		return ((printf("Failed to initialize mutex\n")), 1);
	return (0);
}
