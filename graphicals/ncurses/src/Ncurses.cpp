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
    mvprintw(line, col - str.length() / 2, str.c_str());
}

// int arc::gl::Ncurses::getKey() const
// {
//     return (getch());
// }

extern "C"
arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::Ncurses;
}
