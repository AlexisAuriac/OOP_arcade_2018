/*
** EPITECH, 2018
** drawPerso.cpp
** File description:
** File Pacman for Library games.
*/

#include <unistd.h>
#include "Pacman.hpp"

void Pacman::drawPerso(arc::gl::IGraphicLib *gl)
{
    this->managEvent();
    gl->drawSquare(_Pos.first, _Pos.second, arc::gl::YELLOW);
}

void Pacman::movPerso(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (event == arc::gl::Right || event == arc::gl::Left) {
        if (this->checkPos(_Pos.second, _Pos.first + dir.second) != false) {
            _sDir = dir;
            _eventP = event;
            if (_map[_Pos.second][_Pos.first] == '.')
                _score += 100;
            if (_map[_Pos.second][_Pos.first] == '*')
                _score += 200;
            _map[_Pos.second][_Pos.first] = ' ';
            _Pos.first += dir.second;
            _map[_Pos.second][_Pos.first] = 'C';            
        }
    } else {
        if (this->checkPos(_Pos.second + dir.first, _Pos.first) != false) {
            if (_map[_Pos.second][_Pos.first] == '.')
                _score += 100;
            if (_map[_Pos.second][_Pos.first] == '*')
                _score += 200;
            _map[_Pos.second][_Pos.first] = ' ';
            _sDir = dir;
            _eventP = event;
            _Pos.second += dir.first;
            _map[_Pos.second][_Pos.first] = 'C';
        }
    }
}

bool Pacman::checkGhost()
{
    for (int i = 0; i < 4; i++) {
        if (_Pos == _PosG[i])
            return false;
    }
    return true;
}

void Pacman::checkMov(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (_Pos.first > 0 && _Pos.first < (_posM.first - 1))
        movPerso(dir, event);
    else {
        _map[_Pos.second][_Pos.first] = ' ';
        if (_Pos.first <= 0) {
            _map[_Pos.second][_posM.first - 1] = ' ';
            _Pos.first = _posM.first - 2;
        } else if (_Pos.first >= _posM.first - 1) {
            _map[_Pos.second][0] = ' ';
            _Pos.first = 1;
        }
        _map[_Pos.second][_Pos.first] = 'C';
    }
    if (this->checkGhost() == false)
        _event = arc::gl::Escape;
}

void Pacman::managEvent()
{
    if (_event == arc::gl::Escape)
        return;
    else if (_event == arc::gl::Left)
        this->checkMov({0, -1}, arc::gl::Left);
    else if (_event == arc::gl::Right)
        this->checkMov({0, 1}, arc::gl::Right);
    else if (_event == arc::gl::Up)
        this->checkMov({-1, 0}, arc::gl::Up);
    else if (_event == arc::gl::Down)
        this->checkMov({1, 0}, arc::gl::Down);
    else if (_event == arc::gl::Unknown)
        this->checkMov(_sDir, _eventP);
}