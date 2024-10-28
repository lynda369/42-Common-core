# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 23:52:31 by lybey             #+#    #+#              #
#    Updated: 2024/03/25 02:52:14 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE  = src/push_swap.c\
		  src/check_error.c\
		  lst/ft_lstadd_end.c\
		  lst/ft_lstlast.c\
		  lst/ft_lstnew.c\
		  lst/ft_lstsize.c\
		  lst/ft_lstclear.c\
		  src/init_stack.c\
		  src/push.c\
		  src/rotate.c\
		  src/swap.c\
		  src/reverse_rotate.c\
		  src/algo.c\
		  

OBJS = $(SOURCE:.c=.o)

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g3


LIBFT =	libft/libft.a

PRINTF	= ft_printf/libftprintf.a	

all: $(NAME)

$(LIBFT):
		make -C libft
		
$(PRINTF):
		make -C ft_printf

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME) $(LIBFT) $(PRINTF)
	
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@		

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
	
re: fclean all

.PHONY: all clean fclean re
