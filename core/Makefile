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

tests_run:
	make -C tests

clean:
	$(RM) $(OBJ)
	make clean -C tests

fclean: clean
	$(RM) $(NAME)
	make fclean -C tests

re: fclean all

.PHONY: all tests_run clean fclean re
