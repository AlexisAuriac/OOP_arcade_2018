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
    // std::cout << "Construction" << std::endl;
    _tail.push_back(std::make_pair((_col / 2), (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 1, (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 2, (_row / 2)));
    _run = 1;
    _movx = 1;
    _movy = 0;
}

void Nibbler::drawMap(arc::gl::IGraphicLib *gl)
{
    for (int i = 3; i < (_row - 3); i++) {
        for (int j = 3; j < (_col - 3); j++) {
            if (i == 3 || i == (_row - 4))
                gl->drawSquare(j, i, arc::gl::WHITE);
            if (j == 3 || j == (_col - 4))
                gl->drawSquare(j, i, arc::gl::WHITE);
        }
    }
}

void Nibbler::gameRun(arc::gl::IGraphicLib *gl)
{
    while (_run) {
        gl->clear();
        this->drawMap(gl);
        this->print_snake(gl);
        gl->display();
        this->move_snake();
        if (this->manag_event(gl) == false)
            break;
    }
}

void Nibbler::dir_snake(arc::gl::event_t event)
{
    if (_movy == -1 || _movy == 1) {
        if (event == arc::gl::Right)
            _movx = _movy * -1;
        else
            _movx = _movy * 1;
        _movy = 0;
    } else {
        if (event == arc::gl::Right)
            _movy = _movx * 1;
        else
            _movy = _movx * -1;
        _movx = 0;
    }
}

bool Nibbler::manag_event(arc::gl::IGraphicLib *gl)
{
    arc::gl::event_t event = gl->getEvent();

    if (event == arc::gl::Right)
        dir_snake(event);
    else if (event == arc::gl::Left)
        dir_snake(event);
    else if (event == arc::gl::Escape)
        return false;
    return true;
}

void Nibbler::move_snake()
{
    int save_x = _tail[0].first;
    int save_y = _tail[0].second;
    int tmp_x = 0;
    int tmp_y = 0;

    _tail[0].first += _movx;
    _tail[0]. second += _movy;
    for (int i = 1; i < (int)_tail.size(); i++) {
        tmp_x = _tail[i].first;
        tmp_y = _tail[i].second;
        _tail[i].first = save_x;
        _tail[i].second = save_y;
        save_x = tmp_x;
        save_y = tmp_y;
        if ((_tail[0].first < 4 || _tail[0].first > (_col - 5))
            || _tail[0].second < 4 || _tail[0].second > (_row - 5)) {
            _run = 0;
        }
        usleep(18000);
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