/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <dirent.h>
#include <unistd.h>
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

void arc::Arcade::mainMenu()
{
    _gl->openWindow();

    int cols = _gl->getCols();
    int lines = _gl->getLines();

    _gl->printText("hi, bye, die, my, why, lie, dye, rely, I, nigh, high, fly", cols / 2, lines / 2);
    _gl->display();
    sleep(2);
    _gl->closeWindow();
}

int arc::Arcade::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        init(av[1]);
        // mainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
