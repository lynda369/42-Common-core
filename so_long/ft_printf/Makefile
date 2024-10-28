# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 23:00:34 by lybey             #+#    #+#              #
#    Updated: 2024/02/18 20:22:02 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
			ft_convert_base.c \
			pf_putchar.c \
			pf_putstr.c \
			pf_putnbr.c \
			pf_putnbr_pos.c

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