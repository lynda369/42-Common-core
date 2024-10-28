/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:03:40 by lybey             #+#    #+#             */
/*   Updated: 2024/02/28 17:05:13 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_left_bis(t_game *game)
{
	game->j_player--;
	game->moves++;
	ft_printf("move count %d\n", game->moves);
}

void	move_right_bis(t_game *game)
{
	game->j_player++;
	game->moves++;
	ft_printf("move count %d\n", game->moves);
}

void	move_up_bis(t_game *game)
{
	game->i_player--;
	game->moves++;
	ft_printf("move count %d\n", game->moves);
}

void	move_down_bis(t_game *game)
{
	game->i_player++;
	game->moves++;
	ft_printf("move count %d\n", game->moves);
}
