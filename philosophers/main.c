/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:45:25 by lybey             #+#    #+#             */
/*   Updated: 2024/09/10 12:15:04 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_data		data = {0};
	t_philo				*philo;

	philo = NULL;
	if (ac < 5 || ac > 6)
		return (printf("error argument !\n"), 1);
	if (init_data(&data, ac, av) != 0)
		return (printf("error data !\n"), 1);
	philo = malloc(sizeof(t_philo) * data.nbr_philo);
	if (!philo)
		return (1);
	data.philos = philo;
	if (ft_init_mutex(&data))
		return (free(philo), 0);
	init_forks(&data, philo);
	if (data.nbr_philo == 1)
	{
		routine_one_philo(philo);
		return (free(philo), 0);
	}
	if (!create_philo(&data, philo))
		monitoring(philo);
	wait_philo(&data, philo);
	ft_destroy(&data, philo);
	return (free(philo), 0);
}

int	ft_not_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
		if (is_digit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_destroy(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&philo[i].fork_l);
		i++;
	}
	pthread_mutex_destroy(&data->print_msg);
	pthread_mutex_destroy(&data->all_ate_lock);
	pthread_mutex_destroy(&data->last_meal_lock);
	pthread_mutex_destroy(&data->meals_lock);
	pthread_mutex_destroy(&data->dead_lock);
}

void	thinking(t_philo *philo)
{
	print_msg(" is thinking", philo);
	while ((philo->data->time_die - (get_time()
				- philo->last_meal) > philo->data->time_eat)
		&& dead_is_dead(philo) == 0)
	{
		ft_usleep(100);
	}
}
