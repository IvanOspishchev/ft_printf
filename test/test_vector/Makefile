CC = gcc

KEYS = -Werror -Wextra -Wall

NAME = fs_vector_test

SRC = ../../fs_vector/*.c ../../support_functions/*.c

all:
	@$(CC) $(KEYS) $(NAME).c $(SRC) -o $(NAME)
	./$(NAME)

clean:
	@rm -rf $(NAME)