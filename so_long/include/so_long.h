/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lybey <lybey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:41:06 by lybey             #+#    #+#             */
/*   Updated: 2024/03/09 04:30:12 by lybey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*snow_ball_ptr;
	void	*snow_ptr;
	void	*snow_right_ptr;
	void	*snow_left_ptr;
	void	*snow_tree_ptr;
	void	*snow_exit_ptr;
	int		i_player;
	int		j_player;
	char	**map;
	int		map_height;
	int		map_width;
	int		exit;
	int		player;
	int		item;
	int		col;
	char	*path;
	int		coin;
	int		i_mlx;
	int		j_mlx;
	int		moves;
	t_game *next;
}			t_game;

int			ft_check_ber(char *name_map);
int			check_first_line(t_game *game);
int			check_last_line(t_game *game);
int			check_first_col(t_game *game);
int			check_last_col(t_game *game);
int			check_walls(t_game *game);
int			check_rectangle(t_game *game);
int			check_char(t_game *game);
int			check_epc_count(t_game *game);
int			check_epc(t_game *game);
int			stock_map(char *path, t_game *game);
int			count_char_map(int fd);
int			check_parsing(t_game *game);
int			strlen_so_long(char *str);
void		stock_map_size(t_game *game);
void		player_position(t_game *game);
int			check_flood_fill(char **copy_map);
int			flood_fill(int x, int y, char **copy_map);
int			copy_map(t_game *game);
int			check_big_map(t_game *game);
//mlx
int			handle_input(int keycode, t_game *game);
void		init_images(t_game *game);
void		display_images(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_down(t_game *game);
void		move_up(t_game *game);
void		free_map(char **map);
int			close_game(t_game *game);
void		destroy_imges(t_game *game);
void		move_left_bis(t_game *game);
void		move_right_bis(t_game *game);
void		move_up_bis(t_game *game);
void		move_down_bis(t_game *game);

#endif