SOURCE = main.c parsing.c routine.c init.c utils.c monitor.c

OBJS = $(SOURCE:.c=.o)

INCL = philo.h

NAME = philo

CC = cc

CFLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJS) $(INCL)
	$(CC) $(CFLAGS)  $(SOURCE) -o $(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re