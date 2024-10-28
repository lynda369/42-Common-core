/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:39:27 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:48:57 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 97 || keycode == 65361)
		move_left(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game);
	if (keycode == 115 || keycode == 65364)
		move_down(game);
	if (keycode == 119 || keycode == 65362)
		move_up(game);
	return (0);
}

void	init_images(t_game *game)
{
	game->snow_ball_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"map/snow_ball.xpm", &game->map_width, &game->map_height);
	game->snow_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "map/snow.xpm",
			&game->map_width, &game->map_height);
	game->snow_right_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"map/snow_right.xpm", &game->map_width, &game->map_height);
	game->snow_left_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"map/snow_left.xpm", &game->map_width, &game->map_height);
	game->snow_tree_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"map/snow_tree.xpm", &game->map_width, &game->map_height);
	game->snow_exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"map/snow_exit.xpm", &game->map_width, &game->map_height);
	if (!game->snow_ball_ptr || !game->snow_ptr || !game->snow_right_ptr
		|| !game->snow_left_ptr || !game->snow_tree_ptr
		|| !game->snow_exit_ptr)
	{
		ft_printf("Error\nInit images failed\n");
		close_game(game);
	}
}

void	display_images(t_game *game)
{
	game->i_mlx = 0;
	while (game->map[game->i_mlx])
	{
		game->j_mlx = 0;
		while (game->map[game->i_mlx][game->j_mlx])
		{
			if (game->map[game->i_mlx][game->j_mlx] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->snow_tree_ptr, game->j_mlx * 60, game->i_mlx * 60);
			if (game->map[game->i_mlx][game->j_mlx] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->snow_left_ptr, game->j_mlx * 60, game->i_mlx * 60);
			if (game->map[game->i_mlx][game->j_mlx] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->snow_exit_ptr, game->j_mlx * 60, game->i_mlx * 60);
			if (game->map[game->i_mlx][game->j_mlx] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->snow_ptr, game->j_mlx * 60, game->i_mlx * 60);
			if (game->map[game->i_mlx][game->j_mlx] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->snow_ball_ptr, game->j_mlx * 60, game->i_mlx * 60);
			game->j_mlx++;
		}
		game->i_mlx++;
	}
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->i_player = i;
				game->j_player = j;
			}
			j++;
		}
		i++;
	}
}
