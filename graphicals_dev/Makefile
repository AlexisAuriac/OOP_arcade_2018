##
## EPITECH PROJECT, 2018
## arcade
## File description:
## Makefile for grapical libs.
##

LIBS	=	ncurses		\
			SFML

all: libs

libs:
	for i in $(LIBS); do \
		make -C $$i; \
	done

clean:
	for i in $(LIBS); do \
		make clean -C $$i; \
	done

fclean:
	for i in $(LIBS); do \
		make fclean -C $$i; \
	done

re: fclean all

.PHONY: all libs clean fclean re
