/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:30:30 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 19:59:29 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (strlen_so_long(game->map[i]) != game->map_width)
		{
			ft_printf("Error\nMap is not a rectangle\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'E' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'C')
			{
				if (game->map[i][j] != '1' && game->map[i][j] != '0')
				{
					ft_printf("Error\nInvalid char\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_epc(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'C')
				game->item++;
			j++;
		}
		i++;
	}
	if (!check_epc_count(game))
		return (ft_printf("Error\nEPC count not good\n"), 0);
	return (1);
}

int	check_epc_count(t_game *game)
{
	if (game->exit != 1)
		return (0);
	if (game->player != 1)
		return (0);
	if (game->item < 1)
		return (0);
	return (1);
}

void	stock_map_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game->map)
		return (ft_printf("Error\nMap does not exist\n"), exit(1));
	if (!game->map[0])
		return (ft_printf("Error\nFile is empty\n"), free(game->map), exit(1));
	while (game->map[i][j])
	{
		j++;
		game->map_width = j;
	}
	while (game->map[i])
	{
		i++;
		game->map_height = i;
	}
}
