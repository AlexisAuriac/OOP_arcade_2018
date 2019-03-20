##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for arcade core.
##

CXX			?=	g++

SRC			=	main.cpp	\
				Arcade.cpp	\
				Error.cpp

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I include

CXXFLAGS	+=	-Wall -Wextra

LDFLAGS		=	-ldl

NAME		=	arcade

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
