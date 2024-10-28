/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:07:10 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 19:39:39 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_flood_fill(char **copy_map)
{
	int	i;
	int	j;

	j = 0;
	while (copy_map[j])
	{
		i = 0;
		while (copy_map[j][i])
		{
			if (copy_map[j][i] == 'E')
			{
				ft_printf("Error\nExit unavailable\n");
				return (0);
			}
			if (copy_map[j][i] == 'C')
			{
				ft_printf("Error\nCollectible unavailable\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	flood_fill(int x, int y, char **copy_map)
{
	if (copy_map[x][y] == '1' || copy_map[x][y] == 'X' || copy_map[x][y] == 'E')
	{
		copy_map[x][y] = 'X';
		return (0);
	}
	copy_map[x][y] = 'X';
	if (flood_fill(x, y - 1, copy_map) || flood_fill(x, y + 1, copy_map)
		|| flood_fill(x - 1, y, copy_map) || flood_fill(x + 1, y, copy_map))
		return (1);
	return (0);
}

int	copy_map(t_game *game)
{
	int		i;
	char	**copy_map;

	i = 0;
	copy_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy_map)
		return (0);
	while (i < game->map_height)
	{
		copy_map[i] = ft_strdup(game->map[i]);
		if (!copy_map[i])
		{
			while (i > 0)
				free(copy_map[i--]);
			return (free(copy_map), 0);
		}
		i++;
	}
	copy_map[i] = NULL;
	flood_fill(game->i_player, game->j_player, copy_map);
	if (!check_flood_fill(copy_map))
		return (free_map(copy_map), 0);
	return (free_map(copy_map), 1);
}
