NAME	= AForm
SRC		= main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp
OBJ		= $(SRC:.cpp=.o)
INCLUDE	= 	Bureaucrat.hpp \
			Form.hpp \
			PresidentialPardonForm.hpp \
			ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re