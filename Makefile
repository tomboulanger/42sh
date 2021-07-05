##
## EPITECH PROJECT, 2020
## makefile
## File description:
## bsq
##

SRC		=	$(wildcard ./src/binaries/*.c)		\
			$(wildcard ./src/builtins/*.c)		\
			$(wildcard ./src/core_build/*.c)	\
			$(wildcard ./src/env/*.c)			\
			$(wildcard ./src/utils/*.c)			\

OBJ		=	$(SRC:.c=.o)

NAME	=	42sh

CFLAGS	=	-W -Wall -Wextra -g

all:	$(NAME)
		@echo -e "\033[0;34m<$(NAME) has been created>\033[00m"

$(NAME):	$(OBJ)
	gcc $(OBJ) -W -Wall -Wextra -pedantic -lncurses -g3 -o $(NAME)
	@echo -e "\033[0;34m<deleted all .o>\033[00m"
	rm -f $(OBJ)

clean:
	@echo -e "\033[0;34m<Deleting useless files>\033[00m"
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
