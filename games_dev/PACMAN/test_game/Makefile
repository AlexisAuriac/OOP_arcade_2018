##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for NIBBLER Games.
##

CXX         ?=  g++

SRC         =   main.cpp\
                Pacman.cpp

SRC         :=  $(addprefix src/, $(SRC)) ../../../core/src/Error.cpp

OBJ         =   $(SRC:.cpp=.o)

CPPFLAGS    +=  -I include -I ../../../core/include

CXXFLAGS    +=  -Wall -Wextra

LDFLAGS		+=	-ldl

NAME        =   essaie

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test