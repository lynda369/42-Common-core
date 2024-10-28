/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:30:49 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 20:49:08 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_parsing(t_game *game)
{
	if (!check_rectangle(game))
		return (0);
	if (!check_char(game))
		return (0);
	if (!check_epc(game))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!copy_map(game))
		return (0);
	return (1);
}

int	check_big_map(t_game *game)
{
	if (game->map_height > 18 || game->map_width > 32)
		return (ft_printf("Error\nMap is too big\n"), 0);
	return (1);
}
