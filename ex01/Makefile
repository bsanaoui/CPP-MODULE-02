NAME = Fixed

CC = clang++
FLAGS = -Werror -Wextra -Wall

SRC = Fixed.cpp main.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) $(FLAG) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :

re : fclean all