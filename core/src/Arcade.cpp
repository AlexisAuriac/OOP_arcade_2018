/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include <string>
#include "Arcade.hpp"
#include "Error.hpp"

void arc::Arcade::handleArgumentErrors(
    int ac,
    __attribute__((unused)) char **av)
{
    if (ac != 2)
        throw arc::err::Argument();
}

void arc::Arcade::loadInitLib(const std::string &libName)
{
}

int arc::Arcade::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        loadInitLib(av[1]);
        // openMainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}