/*
** EPITECH, 2018
** Pacman.cpp
** File description:
** File Pacman for Library games.
*/

#include "Pacman.hpp"

void arc::game::Pacman::drawScore()
{
    gl::textParams_t params;
    std::string score = "Score: ";

    params.x = 0;
    params.y = 0;
    _gl->printText(score + std::to_string(_score), params);
}

void arc::game::Pacman::drawMap()
{
    for (int x = 1 ; x <= _posM.first + 1 ; ++x) {
        for (int y = 0 ; y < _posM.second ; ++y) {
            if (_map[x][y] == 'X')
                _gl->drawSquare(y, x, gl::BLUE);
            else if (_map[x][y] == '.' || _map[x][y] == '*') {
                gl::textParams_t text;
                text.x = y;
                text.y = x;
                _gl->printText((_map[x][y] == '.') ? "." : "*", text);
            } else if (_map[x][y] == 'C') {
                _pos.first = y;
                _pos.second = x;
            } else if (_map[x][y] == 'G')
                _posG.push_back(std::make_pair(y, x));
            else if (_map[x][y] == '-')
                _door = std::make_pair(y, x);
        }
    }
}
