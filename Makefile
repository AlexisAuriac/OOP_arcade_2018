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
	make -C games_dev

graphicals:
	make -C graphicals_dev

tests_run:
	make -C tests

clean:
	make clean -C tests
	make clean -C core
	make clean -C games_dev
	make clean -C graphicals_dev

fclean: clean
	make fclean -C tests
	make fclean -C core
	make fclean -C games_dev
	make fclean -C graphicals_dev

re: fclean all

.PHONY: all core games graphicals tests_run clean fclean re
