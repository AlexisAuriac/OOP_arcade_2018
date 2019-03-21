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
    // start_color();
    // for (int i = 0 ; i < 16 ; ++i) {
    //     for (int j = 0 ; j < 16 ; ++j)
    //         init_pair(i * 16 + j, i, j);
    // }
}

void arc::gl::Ncurses::closeWindow()
{
    endwin();
}

void arc::gl::Ncurses::display()
{
    move(0, 0);
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


void arc::gl::Ncurses::printText(
    const std::string &str,
    const textParams_t &params)
{
    int len = str.length();
    int correctedCol;

    if (params.x + len > COLS)
        correctedCol = COLS - len;
    else {
        correctedCol = params.x - len / 2;
        if (correctedCol < 0)
            correctedCol = 0;
    }
    attron(COLOR_PAIR((COLOR_WHITE + 8) * 16 + COLOR_BLACK));
    if (params.bold)
        attron(A_BOLD);
    else
        attroff(A_BOLD);
    mvprintw(params.y, correctedCol, str.c_str());
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
