/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:49:14 by lybey             #+#    #+#             */
/*   Updated: 2024/09/08 21:53:20 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res > INT_MIN) && (res < INT_MAX))
		return (res * sign);
	else
		return (0);
}

int	is_digit(char *argv)
{
	int	i;

	i = 0;
	if (ft_atoi(argv) == 0)
		return (1);
	while (argv[i])
	{
		if (argv[i] == '-')
			return (1);
		if (argv[i] < '0' && argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

// Ici j'initialise les arguments que je recois lorsque je lance mon programme
// number_of_philosophers - time_to_die - time_to_eat - time_to_sleep
// - number_of_times_each_philosopher_must_eat (optional argument)

int	init_data(t_data *data, int ac, char **av)
{
	if (ft_not_number(ac, av))
		return (1);
	data->nbr_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->start_time = get_time();
	data->philo_death = 0;
	data->start_time = get_time();
	if (ac == 6)
		data->nbr_meals = ft_atoi(av[5]);
	else
		data->nbr_meals = -1;
	return (0);
}
