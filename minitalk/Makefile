# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lybey <lybey@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 02:18:21 by lybey             #+#    #+#              #
#    Updated: 2024/04/14 23:23:43 by lybey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		=  client.c utils.c
SERVER		=  server.c utils.c

NAME_CLI	= client
NAME_SRV	= server

OBJ_CLI		= $(CLIENT:.c=.o)
OBJ_SRV 	= $(SERVER:.c=.o)
CC			= cc -Wall -Wextra -Werror  -g3 


all:	 $(NAME_CLI) $(NAME_SRV)

$(NAME_CLI):		$(OBJ_CLI) 
					$(CC) -o $(NAME_CLI) $(CLIENT)
					
$(NAME_SRV):		$(OBJ_SRV) 
					$(CC) -o $(NAME_SRV) $(SERVER)

clean: 
		rm -rf ${OBJ_CLI} ${OBJ_SRV}

fclean: 		clean
		rm -rf ${NAME_CLI} ${NAME_SRV}

re:          	fclean all

.PHONY:         all clean fclean re