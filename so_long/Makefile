# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 13:46:03 by lybey             #+#    #+#              #
#    Updated: 2024/02/28 21:12:01 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =   src/main.c \
			src/stock_map.c \
			src/check_map.c \
			src/check_walls.c \
			src/parsing.c \
			src/check_mlx.c \
			src/utils.c \
			src/moves.c \
			src/moves_bis.c \
			src/close_game.c \
			src/flood_fill.c
				
OBJS      	=    $(SRCS:.c=.o)
NAME       	 =   so_long
HEADER		=	include/so_long.h
CC 			=	cc
CFLAGS       =   -g -Wall -Werror -Wextra -g3
INCL  		 =    -I. -I/usr/include -Ilibft -Ift_printf -Imlx

MLXFLAGS     =    -lXext -lmlx_Linux -lX11 -lm -lz -Lmlx -L/usr/lib -lmlx
# MLXFLAGS	=	-lmlx -lXext -lX11


LIBFT        =    libft/libft.a

LIBFT_DIR    =    libft

PRINTF		 =	ft_printf/libftprintf.a

PRINTF_DIR	 =  ft_printf

MLX 		=	mlx/libmlx.a mlx/libmlx_Linux.a

MLX_DIR 		=	mlx

all: $(NAME)

$(LIBFT):
		make -C libft

$(PRINTF):
		make -C ft_printf

$(MLX):
		make -C mlx


$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(HEADER)
		$(CC) $(CFLAGS) -o  $(NAME) $(INC) $(MLXFLAGS) $(OBJS) $(LIBFT)  $(PRINTF) $(MLX)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re