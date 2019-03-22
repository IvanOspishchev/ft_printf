CC = gcc

KEYS = -Werror -Wextra -Wall

NAME = parsing_test

SRC = ../../fs_vector/*.c ../../support_functions/*.c ../../parsing/*.c

all:
	@$(CC) $(KEYS) $(NAME).c $(SRC) -o $(NAME)
	./$(NAME)

clean:
	@rm -rf $(NAME)