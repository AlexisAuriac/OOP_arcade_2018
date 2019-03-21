/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include <string>
#include "Arcade.hpp"

void arc::Arcade::displayMenu(
    const std::string &listName,
    std::list<std::string> entries,
    int col,
    int curX,
    int curY)
{
    int lines = _gl->getLines();
    gl::textParams_t params;
    int i = 0;

    params.x = col;
    params.y = lines / 2 + (entries.size() / 2) - entries.size() - 1;
    params.bold = true;
    _gl->printText(listName, params);
    params.bold = false;
    for (const std::string &s : entries) {
        ++params.y;
        if (s == _currGl)
            params.colorFg = arc::gl::GREEN;
        else
            params.colorFg = arc::gl::WHITE;
        if (i == curY)
            params.colorBg = arc::gl::BLUE;
        else
            params.colorBg = arc::gl::BLACK;
        _gl->printText(s, params);
        ++i;
    }
}

void arc::Arcade::mainMenu()
{
    unsigned int x = 0;
    unsigned int y = 0;
    arc::gl::event_t event = 0;

    _gl->openWindow();

    for (int i = 0 ; i < 40 ; ++i)
        _gls.push_back(std::to_string(i));
    for (int i = 0 ; i < 40 ; ++i)
        _games.push_back(std::to_string(i));

    while ((event = _gl->getEvent()) != arc::gl::Escape) {
        _gl->display();
        _gl->clear();
        displayMenu("LIBS", _gls, _gl->getCols() / 4, x, y);
        displayMenu("GAMES", _games, _gl->getCols() / 4 * 3, x, y);
        if (event == arc::gl::Down) {
            ++y;
            if (y > _gls.size() - 1)
                y = 0;
        } else if (event == arc::gl::Up) {
            if (y == 0)
                y = _gls.size() - 1;
            else
                --y;
        }
    }
    _gl->closeWindow();
}
