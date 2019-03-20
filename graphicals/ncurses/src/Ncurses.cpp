/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** file Ncurse
*/

#include <iostream>
#include <ncurses.h>
#include "Ncurses.hpp"

// void arc::gl::Ncurses::openWindow()
// {
//     // initscr();
//     std::cout << "openWindow" << std::endl;

// }

// void arc::gl::Ncurses::closeWindow()
// {
//     // endwin();
//     std::cout << "closeWindow" << std::endl;
// }

// arc::gl::Ncurses::Ncurses()
// {
//     initscr();
//     std::cout << "Initialistation of ncurses library" << std::endl;

// }

// arc::gl::Ncurses::~Ncurses()
// {
//     endwin();
//     std::cout << "Stop of ncurses library" << std::endl;
// }

// void arc::gl::Ncurses::loop()
// {
//     std::string str1 = "PACMAN/NIBBLER";
//     std::string str2 = "Ncurse/SFML";
//     move(LINES / 2, (COLS / 2) - 10);
//     printw(str1.c_str());
//     move((LINES / 2) + 3, (COLS / 2) - 10);
//     printw(str2.c_str());
//     refresh();
// }

// int arc::gl::Ncurses::getKey() const
// {
//     return (getch());
// }

extern "C"
// arc::gl::IGraphicLib *entryPoint()
void *entryPoint()
{
    return new arc::gl::Ncurses();
}
