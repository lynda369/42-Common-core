/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:54:33 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:05:08 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_left(t_game *game)
{
	if (game->map[game->i_player][game->j_player - 1] == '1')
		return ;
	if (game->map[game->i_player][game->j_player - 1] == 'C')
	{
		game->item--;
		game->map[game->i_player][game->j_player - 1] = 'L';
	}
	if (game->map[game->i_player][game->j_player - 1] == 'E' && game->item == 0)
	{
		ft_printf("GAGNE");
		close_game(game);
	}
	if (game->map[game->i_player][game->j_player - 1] == 'E' && game->item != 0)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_ptr,
		game->j_player * 60, game->i_player * 60);
	move_left_bis(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_left_ptr,
		game->j_player * 60, game->i_player * 60);
}

void	move_right(t_game *game)
{
	if (game->map[game->i_player][game->j_player + 1] == '1')
		return ;
	if (game->map[game->i_player][game->j_player + 1] == 'C')
	{
		game->item--;
		game->map[game->i_player][game->j_player + 1] = 'L';
	}
	if (game->map[game->i_player][game->j_player + 1] == 'E' && game->item == 0)
	{
		ft_printf("GAGNE");
		close_game(game);
	}
	if (game->map[game->i_player][game->j_player + 1] == 'E' && game->item != 0)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_ptr,
		game->j_player * 60, game->i_player * 60);
	move_right_bis(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_right_ptr,
		game->j_player * 60, game->i_player * 60);
}

void	move_down(t_game *game)
{
	if (game->map[game->i_player + 1][game->j_player] == '1')
		return ;
	if (game->map[game->i_player + 1][game->j_player] == 'C')
	{
		game->item--;
		game->map[game->i_player + 1][game->j_player] = 'L';
	}
	if (game->map[game->i_player + 1][game->j_player] == 'E' && game->item == 0)
	{
		ft_printf("GAGNE");
		close_game(game);
	}
	if (game->map[game->i_player + 1][game->j_player] == 'E' && game->item != 0)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_ptr,
		game->j_player * 60, game->i_player * 60);
	move_down_bis(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_left_ptr,
		game->j_player * 60, game->i_player * 60);
}

void	move_up(t_game *game)
{
	if (game->map[game->i_player - 1][game->j_player] == '1')
		return ;
	if (game->map[game->i_player - 1][game->j_player] == 'C')
	{
		game->item--;
		game->map[game->i_player - 1][game->j_player] = 'L';
	}
	if (game->map[game->i_player - 1][game->j_player] == 'E' && game->item == 0)
	{
		ft_printf("GAGNE");
		close_game(game);
	}
	if (game->map[game->i_player - 1][game->j_player] == 'E' && game->item != 0)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_ptr,
		game->j_player * 60, game->i_player * 60);
	move_up_bis(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->snow_right_ptr,
		game->j_player * 60, game->i_player * 60);
}
