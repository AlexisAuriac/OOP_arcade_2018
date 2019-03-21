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

void arc::Arcade::displayMenu(
    const std::string &listName,
    std::list<std::string> entries,
    int col)
{
    int lines = _gl->getLines();
    gl::textParams_t params;

    params.x = col;
    params.y = lines / 2 + (entries.size() / 2) - entries.size() - 1;
    params.bold = true;
    _gl->printText(listName, params);
    params.bold = false;
    for (const std::string &s : entries) {
        ++params.y;
        _gl->printText(s, params);
    }
}

void arc::Arcade::mainMenu()
{
    _gl->openWindow();

    for (int i = 0 ; i < 40 ; ++i)
        _gls.push_back(std::to_string(i));
    for (int i = 0 ; i < 40 ; ++i)
        _games.push_back(std::to_string(i));
    displayMenu("LIBS", _gls, _gl->getCols() / 4);
    displayMenu("GAMES", _games, _gl->getCols() / 4 * 3);
    _gl->display();
    sleep(100);
    _gl->closeWindow();
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
