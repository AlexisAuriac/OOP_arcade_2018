##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for games.
##

GAMES	=

all: games

games:
	for i in $(GAMES); do \
		make -C $$i; \
	done

clean:
	for i in $(GAMES); do \
		make clean -C $$i; \
	done

fclean:
	for i in $(GAMES); do \
		make fclean -C $$i; \
	done

re: fclean all

.PHONY: all games clean fclean re
