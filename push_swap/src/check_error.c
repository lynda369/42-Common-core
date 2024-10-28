/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:22:58 by lybey             #+#    #+#             */
/*   Updated: 2024/03/25 03:15:51 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_int(char *num)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (num[i] == '-' || num[i] == '+')
	{
		i++;
		sign = 1;
	}
	while (num[i] != '\0')
	{
		if (ft_isdigit(num[i]) == 0)
			return (ft_printf("Error\n"), 0);
		i++;
	}
	if (sign == 1 && i == 1)
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	check_error(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_is_int(av[i]) == 0)
			return (0);
		i++;
	}
	if (!is_duplicate(av))
		return (0);
	if (!is_max_min(av))
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	is_max_min(char **av)
{
	int				i;
	long long int	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if ((nb > INT_MAX) || (nb < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}
