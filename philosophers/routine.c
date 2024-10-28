/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:56:01 by lybey             #+#    #+#             */
/*   Updated: 2024/09/08 20:01:47 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Fonction routine dans laquelle nous allons eat sleep et think
void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(100);
	while (dead_is_dead(philo) == 0)
	{
		if (eating(philo) == 1)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int	routine_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	print_msg(" has taken a fork", philo);
	pthread_mutex_lock(philo->fork_r);
	print_msg(" has taken a fork", philo);
	print_msg(" is eating", philo);
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->last_meal_lock);
	ft_usleep(philo->data->time_eat);
	if (++philo->meals == philo->data->nbr_meals)
	{
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_lock(&philo->data->all_ate_lock);
		philo->data->all_ate++;
		pthread_mutex_unlock(&philo->data->all_ate_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
	return (0);
}

// Fonction eating dans laquelle on va print les messages
//  des fourchettes prises et sleep le time_to_eat

int	eating(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->id % 2 == 0)
	{
		if (routine_even(philo) != 0)
			return (1);
	}
	else if (philo->id % 2 != 0)
	{
		if (routine_odd(philo) != 0)
			return (1);
	}
	return (0);
}

int	routine_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	print_msg(" has taken a fork", philo);
	pthread_mutex_lock(&philo->fork_l);
	print_msg(" has taken a fork", philo);
	print_msg(" is eating", philo);
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->last_meal_lock);
	ft_usleep(philo->data->time_eat);
	if (++philo->meals == philo->data->nbr_meals)
	{
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(&philo->fork_l);
		pthread_mutex_lock(&philo->data->all_ate_lock);
		philo->data->all_ate++;
		pthread_mutex_unlock(&philo->data->all_ate_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&philo->fork_l);
	return (0);
}

void	sleeping(t_philo *philo)
{
	print_msg(" is sleeping", philo);
	ft_usleep(philo->data->time_sleep);
}
