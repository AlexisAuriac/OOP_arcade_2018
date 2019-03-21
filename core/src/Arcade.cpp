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

#include <algorithm>

void print(const std::string &value)
{
    std::cout << value.c_str() << std::endl;
}

void arc::Arcade::ReadLibDir(
    const char *dirName,
    std::list<std::string> &fList)
{
    DIR *dir = opendir(dirName);
    struct dirent *file = nullptr;

    if (dir == nullptr)
        throw arc::err::Asset("opendir", dirName, strerror(errno));
    while (true) {
        file = readdir(dir);
        if (!file)
            break;
        else if (file->d_name[0] == '.')
            continue;
        fList.push_back(file->d_name);
    }
    fList.sort();
    closedir(dir);
}

void arc::Arcade::getAssets()
{
    ReadLibDir(arc::GAMES_DIR, _games);
    ReadLibDir(arc::GLS_DIR, _gls);
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
        _glLoader.loadLib(av[1]);
        _gl = _glLoader.getInstance();
        getAssets();
        mainMenu();
    } catch(const arc::err::Arcade &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
