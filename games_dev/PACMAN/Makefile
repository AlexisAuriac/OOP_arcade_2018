##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for NIBBLER Games.
##

CXX         ?=  g++

SRC         =   Pacman.cpp\

SRC         :=  $(addprefix src/, $(SRC))

OBJ         =   $(SRC:.cpp=.o)

CPPFLAGS    +=  -I include -I ../../core/include

CXXFLAGS    +=  -Wall -Wextra -fPIC

LDFLAGS     +=  -lncurses

NAME        =   ../../games/lib_arcade_nibbler.so

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -shared -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
