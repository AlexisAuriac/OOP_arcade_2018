/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the Nibbler's class methods relative to display.
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Nibbler.hpp"

void arc::game::Nibbler::drawMap()
{
    for (int i = 3 ; i < (_row - 3) ; ++i) {
        for (int j = 3 ; j < (_col - 3) ; ++j) {
            if (i == 3 || i == (_row - 4))
                _gl->drawSquare(j, i, gl::WHITE);
            if (j == 3 || j == (_col - 4))
                _gl->drawSquare(j, i, gl::WHITE);
        }
    }
}

void arc::game::Nibbler::printScore()
{
    gl::textParams_t text;
    std::string score = "Score: ";

    text.x = 0;
    text.y = 0;
    score += std::to_string(_tabScore[_index].second);
    text.colorFg = gl::WHITE;
    text.colorBg = gl::BLACK;
    _gl->printText(score, text);
}

void arc::game::Nibbler::printSnake()
{
    _gl->drawSquare(_fruit.first, _fruit.second, gl::RED);
    for (unsigned int i = 0 ; i < _tail.size(); ++i) {
        if (i == 0)
            _gl->drawSquare(_tail[i].first, _tail[i].second, gl::BLUE);
        else
            _gl->drawSquare(_tail[i].first, _tail[i].second, gl::GREEN);
    }
}

void arc::game::Nibbler::display()
{
    _gl->clear();
    drawMap();
    printSnake();
    printScore();
    _gl->display();
}
