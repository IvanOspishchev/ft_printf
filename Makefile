# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 20:11:10 by ivan              #+#    #+#              #
#    Updated: 2019/03/26 09:59:06 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc

NAME := libftprintf.a

FLAGS :=  -c -Wall -Wextra -Werror -g

SRC_DIR := . fs_vector parsing preparation support_function
DIR_OBJ := obj

INCLUDES := I .

SOURCES := $(wildcard $(DIR_VEC),  *.c)
OBJECTS := $(SOURCE: .c=.o)

SRCS := $(addprefix ../,$(SRC_DIR))
SEARCH_WILD := $(addsuffix /*.c, $(SRC_DIR))

VPATH := $(SRC_DIR)

all: $(NAME)
	
	$(notdir $(patsubst %.c,%.o$(wildcard $(SEARCH_WILD))))
		$(CC) $^ -o $@

$(NAME):
	$(CC) $(FLAGS) $(addprefix ,$(SEARCH_WILD)) $<
	ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OBJECTS))
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re