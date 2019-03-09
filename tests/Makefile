##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for unitests.
##

SRC		=

SRC_UT	=

OBJ		=	$(SRC:.cpp=.o)	\
			$(SRC_UT:.cpp=.o)

CPPFLAGS	+=	-I ../include

CXXFLAGS	+=	-Wall -Wextra --coverage

LDFLAGS		+=	-lcriterion -lgcov

NAME		=	units

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) $(SRC:.cpp=.gcda)
		$(RM) $(SRC:.cpp=.gcno)
		$(RM) $(SRC_UT:.cpp=.gcda)
		$(RM) $(SRC_UT:.cpp=.gcno)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	all  clean  fclean  re
