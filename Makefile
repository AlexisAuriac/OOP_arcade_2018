##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for arcade.
##

CXX			?=	g++

SRC			=	main.cpp

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I include

CXXFLAGS	+=	-Wall -Wextra

NAME		=	arcade

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

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