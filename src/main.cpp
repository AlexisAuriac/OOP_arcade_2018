/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include "Arcade.hpp"
#include "Error.hpp"

void error_handling(int ac, char **av)
{
	if (ac != 2)
		throw arc::err::Argument();
}

int arc::Arcade::run(int ac, char **av)
{
	try {
		error_handling(ac, av);
	} catch(const arc::err::Arcade &e) {
		std::cerr << e.what() << std::endl;
		return arc::FAILURE;
	}
	return arc::SUCCESS;
}

int main(int ac, char **av)
{
	arc::Arcade app;

	return app.run(ac, av);
}