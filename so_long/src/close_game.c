/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:37:03 by lybey             #+#    #+#             */
/*   Updated: 2024/02/27 23:35:25 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

int	close_game(t_game *game)
{
	free_map(game->map);
	destroy_imges(game);
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
		{
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		}
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}

void	destroy_imges(t_game *game)
{
	if (game->snow_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_ptr);
	if (game->snow_ball_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_ball_ptr);
	if (game->snow_tree_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_tree_ptr);
	if (game->snow_right_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_right_ptr);
	if (game->snow_left_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_left_ptr);
	if (game->snow_exit_ptr)
		mlx_destroy_image(game->mlx_ptr, game->snow_exit_ptr);
}
