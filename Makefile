##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for arcade core, graphical libs and games.
##

all: core graphicals games

core:
	make -C core

games:
	make -C games

graphicals:
	make -C graphicals

tests_run:
	make -C tests

clean:
	make clean -C tests
	make clean -C core
	make clean -C games
	make clean -C graphicals

fclean: clean
	make fclean -C tests
	make fclean -C core
	make fclean -C games
	make fclean -C graphicals

re: fclean all

.PHONY: all core games graphicals tests_run clean fclean re
