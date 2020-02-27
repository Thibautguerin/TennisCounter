##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile struct
##

SRC	=	src/main.c		\
		src/display.c		\
		src/count_point.c	\
		src/manual_and_annexe.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	tennis

all:	$(NAME)

$(NAME):	$(SRC)
	gcc $(SRC)-o $(NAME) -Iinclude -W -Wall -Wextra

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
