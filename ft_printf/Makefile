# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 23:00:34 by lybey             #+#    #+#              #
#    Updated: 2023/09/18 21:30:09 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_convert_base.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_pos.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include

NAME	=	libftprintf.a

$(NAME):	$(OBJS) ft_printf.h
				ar -rcs $(NAME) $(OBJS)

all :     	$(NAME)

%.o: %.c ft_printf.h
	$(CC) -I. -c $< -o $@

clean: 	
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re