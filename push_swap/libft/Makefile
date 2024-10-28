# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 22:28:07 by lybey             #+#    #+#              #
#    Updated: 2024/03/15 00:33:36 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c

# BONUS = 
		
OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include

NAME	=	libft.a

$(NAME):	$(OBJS)
				ar -rcs $(NAME) $(OBJS)

# bonus:	$(OBJS) $
# 				ar -rcs $(NAME) $(OBJS)

all :     	$(NAME)

clean: 	
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re