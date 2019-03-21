/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** file Ncurse
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Ncurses.hpp"

void arc::gl::Ncurses::openWindow()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
}

void arc::gl::Ncurses::closeWindow()
{
    endwin();
}

void arc::gl::Ncurses::display()
{
    refresh();
}

void arc::gl::Ncurses::clear()
{
    clear();
}

int arc::gl::Ncurses::getCols()
{
    return COLS;
}

int arc::gl::Ncurses::getLines()
{
    return LINES;
}

void arc::gl::Ncurses::printText(const std::string &str, int col, int line)
{
    mvprintw(line, col, str.c_str());
}

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
arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::Ncurses;
}
