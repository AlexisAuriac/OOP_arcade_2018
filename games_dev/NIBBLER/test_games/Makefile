##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for NIBBLER Games.
##

CXX         ?=  g++

SRC         =   main.cpp\
                Nibbler.cpp

SRC         :=  $(addprefix src/, $(SRC))

OBJ         =   $(SRC:.cpp=.o)

CPPFLAGS    +=  -I include

CXXFLAGS    +=  -Wall -Wextra

LDFLAGS     +=  -lncurses

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