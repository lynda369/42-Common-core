/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:46:47 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:50:05 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	strlen_so_long(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_ber(char *name_map)
{
	char	*str;

	str = ft_strnstr(name_map, ".ber", strlen_so_long(name_map));
	if (strlen_so_long(str) == 4 && strlen_so_long(name_map) > 4)
		return (1);
	ft_printf("Error\nInvalid file name\n");
	return (0);
}
