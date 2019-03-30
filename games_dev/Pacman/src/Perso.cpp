/*
** EPITECH, 2018
** drawPerso.cpp
** File description:
** File Pacman for Library games.
*/

#include <unistd.h>
#include "Pacman.hpp"

void Pacman::drawPerso()
{
    manageEvent();
    _gl->drawSquare(_pos.first, _pos.second, arc::gl::YELLOW);
}

void Pacman::movPerso(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (event == arc::gl::Right || event == arc::gl::Left) {
        if (checkPos(_pos.second, _pos.first + dir.second) != false) {
            _sDir = dir;
            _eventP = event;
            if (_map[_pos.second][_pos.first] == '.')
                _score += 100;
            if (_map[_pos.second][_pos.first] == '*')
                _score += 200;
            _map[_pos.second][_pos.first] = ' ';
            _pos.first += dir.second;
            _map[_pos.second][_pos.first] = 'C';
        }
    } else {
        if (checkPos(_pos.second + dir.first, _pos.first) != false) {
            if (_map[_pos.second][_pos.first] == '.')
                _score += 100;
            if (_map[_pos.second][_pos.first] == '*')
                _score += 200;
            _map[_pos.second][_pos.first] = ' ';
            _sDir = dir;
            _eventP = event;
            _pos.second += dir.first;
            _map[_pos.second][_pos.first] = 'C';
        }
    }
}

bool Pacman::checkGhost()
{
    for (int i = 0 ; i < 4 ; ++i) {
        if (_pos == _posG[i])
            return false;
    }
    return true;
}

void Pacman::checkMove(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (_pos.first > 0 && _pos.first < (_posM.first - 1))
        movPerso(dir, event);
    else {
        _map[_pos.second][_pos.first] = ' ';
        if (_pos.first <= 0) {
            _map[_pos.second][_posM.first - 1] = ' ';
            _pos.first = _posM.first - 2;
        } else if (_pos.first >= _posM.first - 1) {
            _map[_pos.second][0] = ' ';
            _pos.first = 1;
        }
        _map[_pos.second][_pos.first] = 'C';
    }
    if (checkGhost() == false)
        _event = arc::gl::Escape;
}

void Pacman::manageEvent()
{
    if (_event == arc::gl::Escape)
        return;
    else if (_event == arc::gl::Left)
        checkMove({0, -1}, arc::gl::Left);
    else if (_event == arc::gl::Right)
        checkMove({0, 1}, arc::gl::Right);
    else if (_event == arc::gl::Up)
        checkMove({-1, 0}, arc::gl::Up);
    else if (_event == arc::gl::Down)
        checkMove({1, 0}, arc::gl::Down);
    else if (_event == arc::gl::Unknown)
        checkMove(_sDir, _eventP);
}
