##
## EPITECH PROJECT, 2021
## makefile
## File description:
## faire fichier
##

SRC	=	my_sfml.c \
		textures.c \
		str.c \
		main.c \
		actions.c

OBJ	=	${SRC:.c=.o}

NAME	=	my_runner

all:	${NAME}

$(NAME):	${OBJ}
	gcc -o ${NAME} ${OBJ} -lcsfml-graphics -lcsfml-window -lcsfml-system

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re