/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:40:44 by lybey             #+#    #+#             */
/*   Updated: 2024/09/08 21:17:49 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_is_dead(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->dead_lock);
	i = philo->data->philo_death;
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (i);
}

int	check_if_dead(t_philo *philo, size_t time_to_die)
{
	int	i;

	i = 0;
	time_to_die = philo->data->time_die;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_lock(&philo->data->last_meal_lock);
		if (time_to_die < get_time() - philo[i].last_meal)
		{
			pthread_mutex_unlock(&philo->data->last_meal_lock);
			print_msg(" died", philo);
			pthread_mutex_lock(&philo->data->dead_lock);
			philo->data->philo_death = 1;
			pthread_mutex_unlock(&philo->data->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->data->last_meal_lock);
		i++;
	}
	return (0);
}

int	monitoring(t_philo *philo)
{
	size_t	time_to_die;

	time_to_die = 0;
	while (1)
	{
		if (check_if_dead(philo, time_to_die))
			return (1);
		if (philo->data->nbr_meals != -1)
		{
			pthread_mutex_lock(&philo->data->all_ate_lock);
			if (philo->data->all_ate == philo->data->nbr_philo)
				return (1);
			pthread_mutex_unlock(&philo->data->all_ate_lock);
		}
	}
	return (0);
}

void	*routine_one_philo(void *pointer)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)pointer;
	pthread_mutex_lock(&philo->fork_l);
	print_msg(" has taken a fork", philo);
	ft_usleep(philo->data->time_die);
	pthread_mutex_unlock(&philo->fork_l);
	print_msg(" died", philo);
	return (NULL);
}

void	create_one_philo(t_philo *philo)
{
	if (pthread_create(&philo[0].thread, NULL, &routine_one_philo,
			&philo[0]) != 0)
	{
		ft_destroy(philo->data, philo);
		printf("Failed to create thread\n");
		return ;
	}
	if (pthread_join(philo[0].thread, NULL) != 0)
	{
		ft_destroy(philo->data, philo);
		printf("Failed to create join\n");
		return ;
	}
}
