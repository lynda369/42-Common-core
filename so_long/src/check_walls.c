/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:38:34 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:49:26 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_first_line(t_game *game)
{
	int	j;

	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_last_line(t_game *game)
{
	int	i;
	int	j;

	i = game->map_height - 1;
	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_first_col(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_last_col(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map_width - 1;
	while (game->map[i])
	{
		if (game->map[i][j] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	if (!check_first_line(game))
	{
		ft_printf("Error\nInvalid first line\n");
		return (0);
	}
	if (!check_last_line(game))
	{
		ft_printf("Error\nInvalid last line\n");
		return (0);
	}
	if (!check_first_col(game))
	{
		ft_printf("Error\nInvalid first column\n");
		return (0);
	}
	if (!check_last_col(game))
	{
		ft_printf("Error\nInvalid last column\n");
		return (0);
	}
	return (1);
}
