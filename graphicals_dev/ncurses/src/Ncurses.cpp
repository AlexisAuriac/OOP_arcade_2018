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
    nodelay(stdscr, TRUE);
    start_color();
    for (int i = 0 ; i < 16 ; ++i) {
        for (int j = 0 ; j < 16 ; ++j)
            init_pair(i * 16 + j, i, j);
    }
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
    erase();
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
    int fg = CONNECT_COLORS[params.colorFg];
    int bg = CONNECT_COLORS[params.colorBg];

    if (params.x + len > COLS)
        correctedCol = COLS - len;
    else {
        correctedCol = params.x - len / 2;
        if (correctedCol < 0)
            correctedCol = 0;
    }
    attron(COLOR_PAIR(fg * 16 + bg));
    if (params.bold)
        attron(A_BOLD);
    else
        attroff(A_BOLD);
    mvprintw(params.y, correctedCol, str.c_str());
}

arc::gl::event_t arc::gl::Ncurses::getEvent()
{
    int ch = getch();

    try {
        return CONNECT_EVENTS.at(ch);
    } catch (const std::out_of_range &e) {
        return Unknown;
    }
}

void arc::gl::Ncurses::drawSquare(int x, int y, arc::gl::color_t color)
{
    int ncColor = CONNECT_COLORS[color];

    attron(COLOR_PAIR(ncColor * 16 + ncColor));
    mvprintw(y, x, " ");
}

extern "C"
arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::Ncurses;
}
