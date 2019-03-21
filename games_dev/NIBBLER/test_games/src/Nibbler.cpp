/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Functions a Nibbler games.
*/

#include <iostream>
#include <unistd.h>
#include "Nibbler.hpp"

Nibbler::Nibbler(arc::gl::IGraphicLib *gl)
: _row(gl->getLines()), _col(gl->getCols())
{
    std::cout << "Construction" << std::endl;
    _tail.push_back(std::make_pair((_col / 2), (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 1, (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 2, (_row / 2)));
}

void Nibbler::gameRun(arc::gl::IGraphicLib *gl)
{
    while (1) {
        gl->clear();
        this->print_snake(gl);
        gl->display();
        this->move_snake();
        if (gl->getEvent() == arc::gl::Escape)
            break;
    }
}

void Nibbler::move_snake()
{
    for (int i = 0; i < (int)_tail.size(); i++) {
        _tail[i].first += 1;
        usleep(10000);
    }
}

void Nibbler::print_snake(arc::gl::IGraphicLib *gl)
{
    for (int i = 0; i < (int)_tail.size(); i++) {
        if (i == 0)
            gl->drawSquare(_tail[i].first, _tail[i].second, arc::gl::BLUE);
        else
            gl->drawSquare(_tail[i].first, _tail[i].second, arc::gl::GREEN);
    }
}

Nibbler::~Nibbler()
{
    std::cout << "Destruction" << std::endl;
}