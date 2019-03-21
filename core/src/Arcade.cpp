/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include "Arcade.hpp"
#include "Error.hpp"

arc::Arcade::~Arcade()
{
    delete _gl;
}

void arc::Arcade::handleArgumentErrors(
    int ac,
    __attribute__((unused)) char **av)
{
    if (ac != 2)
        throw arc::err::Argument();
}

int arc::Arcade::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        init(av[1]);
        mainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
