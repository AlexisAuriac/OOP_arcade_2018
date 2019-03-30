##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for SDL2 graphical library.
##

CXX			?=	g++

SRC			=	SDL1.cpp

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I include -I ../../core/include

CXXFLAGS	+=	-Wall -Wextra -fPIC

LDFLAGS		+=	-lSDL -lSDL_ttf

NAME		=	../../graphicals/lib_arcade_sdl1.so

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
