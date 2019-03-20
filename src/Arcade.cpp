/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include "Arcade.hpp"
#include "Error.hpp"

void arc::Arcade::handle_argument_errors(
    int ac,
    __attribute__((unused)) char **av)
{
    if (ac != 2)
        throw arc::err::Argument();
}

int arc::Arcade::run(int ac, char **av)
{
    try {
        handle_argument_errors(ac, av);
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
