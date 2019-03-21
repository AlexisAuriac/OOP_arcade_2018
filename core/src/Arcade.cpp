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

int arc::Arcade::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        _glLoader.loadLib(av[1]);
        _gl = _glLoader.getInstance();
        // _gl->openWindow();
        // _gl->display();
        // _gl->closeWindow();
        // openMainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
