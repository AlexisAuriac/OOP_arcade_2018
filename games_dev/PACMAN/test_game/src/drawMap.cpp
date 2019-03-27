/*
** EPITECH, 2018
** Pacman.cpp
** File description:
** File Pacman for Library games.
*/

#include "Pacman.hpp"

void Pacman::drawScore(arc::gl::IGraphicLib *gl)
{
    arc::gl::textParams_t param;

    param.x = 0;
    param.y = 0;
    gl->printText("Score: ", param);
}

void Pacman::drawMap(arc::gl::IGraphicLib *gl)
{
    for (int x = 1; x <= _posM.first + 1; x++) {
        for (int y = 0; y < _posM.second; y++) {
            if (_map[x][y] == 'X')
                gl->drawSquare(y, x, arc::gl::BLUE);
            else if (_map[x][y] == '.' || _map[x][y] == '*') {
                arc::gl::textParams_t text;
                text.x = y;
                text.y = x;
                gl->printText((_map[x][y] == '.') ? "." : "*", text);
            } else if (_map[x][y] == 'C') {
                _Pos.first = y;
                _Pos.second = x;
            }
            else if (_map[x][y] == 'G')
                _PosG.push_back(std::make_pair(y, x));
            else if (_map[x][y] == '-')
                _door = std::make_pair(y, x);
        }
    }
}