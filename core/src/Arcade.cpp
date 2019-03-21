/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include <string>
#include <unistd.h>
#include "Arcade.hpp"
#include "Error.hpp"

void arc::Arcade::handleArgumentErrors(
    int ac,
    __attribute__((unused)) char **av)
{
    if (ac != 2)
        throw arc::err::Argument();
}

void arc::Arcade::mainMenu()
{
    _gl->openWindow();

    int cols = _gl->getCols();
    int lines = _gl->getLines();

    // std::cout << "cols: " << cols << std::endl;
    // std::cout << "lines: " << lines << std::endl;
    _gl->printText("hello", cols / 2, lines / 2);
    _gl->display();
    sleep(2);
    _gl->closeWindow();
}

int arc::Arcade::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        _glLoader.loadLib(av[1]);
        _gl = _glLoader.getInstance();
        mainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
