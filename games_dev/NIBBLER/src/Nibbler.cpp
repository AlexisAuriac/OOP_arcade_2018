/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Functions a Nibbler games.
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Nibbler.hpp"

Nibbler::Nibbler(arc::gl::IGraphicLib *gl)
: _row(gl->getLines()), _col(gl->getCols())
{
    srand(time(NULL));
    useconds_t arr[] = {0, 0, 0, 25000, 17000, 13000, 10000, 9500,
        9000, 8300, 7600, 6900, 6200, 5600, 5000, 4600, 4200,
        3800, 3650, 3500, 3400, 3325, 3250, 3150, 3100};
    int arr1[] = {0, 0, 0, 0, 100, 150, 225, 300, 400, 525, 675,
        550, 1050, 1275, 1525, 1700, 2000, 2325, 2675, 3050,
        3450, 3875, 4325, 4800, 5300};
    int n = sizeof(arr)/sizeof(arr[0]); 

    for (int i=0; i<n; i++) 
        _tabScore.push_back(std::make_pair(arr[i], arr1[i]));     
    _tail.push_back(std::make_pair((_col / 2), (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 1, (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 2, (_row / 2)));
    _run = 1;
    _movx = 1;
    _movy = 0;
    _index = _tail.size();
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

void Nibbler::posFruit(int flag)
{
    int x = _tail[_tail.size()].first;
    int y = _tail[_tail.size()].second;

    if (_tail.size() <= 3 && flag == 1) {
        _fruit.first = rand()%((_col - 4) - 4) + 4;
        _fruit.second = rand()%((_row - 4) - 4) + 4;
        return;
    }
    else
        _tail.push_back(std::make_pair(x, y));
    _fruit.first = rand()%((_col - 4) - 4) + 4;
    _fruit.second = rand()%((_row - 4) - 4) + 4;
    if (_tail.size() < _tabScore.size())
        _index += 1;
    else {
        _tabScore[_index].first -= 75;
        _tabScore[_index].second += 500;
    }
}

void Nibbler::printScore(arc::gl::IGraphicLib *gl)
{
    arc::gl::textParams_t text;
    std::string score = "Score: ";

    text.x = 0;
    text.y = 0;
    score += std::to_string(_tabScore[_index].second);
    text.colorFg = arc::gl::WHITE;
    text.colorBg = arc::gl::BLACK;
    gl->printText(score, text);
}

void Nibbler::gameRun(arc::gl::IGraphicLib *gl)
{
    this->posFruit(1);
    while (_run) {
        gl->clear();
        this->drawMap(gl);
        this->print_snake(gl);
        this->printScore(gl);
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

void Nibbler::manag_hit()
{
    if ((_tail[0].first < 4 || _tail[0].first > (_col - 5))
        || _tail[0].second < 4 || _tail[0].second > (_row - 5)) {
        _run = 0;
    }
    for (int i = 1; i < (int)_tail.size(); i++) {
        if (_tail[i].first == _tail[0].first
            && _tail[i].second == _tail[0].second) {
            _run = 0;
            return;
        }
    }
    if (_tail[0].first == _fruit.first
        && _tail[0].second == _fruit.second)
        this->posFruit(2);

}

void Nibbler::move_snake()
{
    std::pair <int, int> save(_tail[0].first, _tail[0].second);
    std::pair <int, int> tmp(0, 0);

    _tail[0].first += _movx;
    _tail[0].second += _movy;
    for (int i = 1; i < (int)_tail.size(); i++) {
        tmp = _tail[i];
        _tail[i] = save;
        save = tmp;
        manag_hit();
        usleep(_tabScore[_index].first);
    }
}

void Nibbler::print_snake(arc::gl::IGraphicLib *gl)
{
    gl->drawSquare(_fruit.first, _fruit.second, arc::gl::RED);
    for (int i = 0; i < (int)_tail.size(); i++) {
        if (i == 0)
            gl->drawSquare(_tail[i].first, _tail[i].second, arc::gl::BLUE);
        else
            gl->drawSquare(_tail[i].first, _tail[i].second, arc::gl::GREEN);
    }
}