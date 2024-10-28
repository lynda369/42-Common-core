/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:33:14 by lybey             #+#    #+#             */
/*   Updated: 2024/09/10 11:50:37 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Fonction qui permet d'avoir le temps actuel en ms
size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error gettimeofday\n");
		return (1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// Fonction qui permet de faire sleep le thread pendant x temps

void	ft_usleep(size_t time_sleep)
{
	size_t	time;

	time = get_time();
	while ((get_time() - time) < time_sleep)
		usleep(1000);
}

// Fonction qui sert a print un message predefini (msg) avec
// les mutex de printf et le temps
// + id
// timestamp_in_ms X has taken a fork
// temps_en_ms ID msg

int	print_msg(char *msg, t_philo *philo)
{
	if (dead_is_dead(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->data->print_msg);
	printf("%lu %d%s\n", (get_time() - philo->data->start_time), philo->id,
		msg);
	pthread_mutex_unlock(&philo->data->print_msg);
	return (0);
}

// Fonction qui sert a wait que les threads finissent leurs routines
void	wait_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (philo[i].thread)
		{
			if (pthread_join(philo[i].thread, NULL) != 0)
			{
				printf("Error: phils %d thread join failed\n", philo[i].id);
				return ;
			}
		}
		i++;
	}
}
