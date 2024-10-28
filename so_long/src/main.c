/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:01 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 20:47:53 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_start(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("Error\nMlx init failed\n");
		close_game(game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * 60,
			game->map_height * 60, "My first window!");
	if (game->win_ptr == NULL)
	{
		ft_printf("Error\nWindow creation failed\n");
		close_game(game);
	}
	init_images(game);
	display_images(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->snow_right_ptr, game->j_player * 60, game->i_player
		* 60);
	mlx_key_hook(game->win_ptr, &handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &close_game,
		game);
	mlx_loop(game->mlx_ptr);
	return (1);
}

int	parsing(char **argv, t_game *game)
{
	if (!ft_check_ber(argv[1]))
		return (1);
	game->path = argv[1];
	if (!stock_map(game->path, game))
		return (1);
	stock_map_size(game);
	if (!check_big_map(game))
		close_game(game);
	player_position(game);
	if (!check_parsing(game))
		close_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_game	game = {0};

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (1);
	}
	if (parsing(argv, &game))
		return (1);
	game_start(&game);
	return (0);
}
