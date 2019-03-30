/*
** EPITECH, 2018
** drawPerso.cpp
** File description:
** File Pacman for Library games.
*/

#include <unistd.h>
#include "Pacman.hpp"

void arc::game::Pacman::drawPerso()
{
    manageEvent();
    _gl->drawSquare(_pos.first, _pos.second, gl::YELLOW);
}

void arc::game::Pacman::movPerso(std::pair <int, int> dir, gl::event_t event)
{
    if (event == gl::Right || event == gl::Left) {
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

bool arc::game::Pacman::checkGhost()
{
    for (int i = 0 ; i < 4 ; ++i) {
        if (_pos == _posG[i])
            return false;
    }
    return true;
}

void arc::game::Pacman::checkMove(std::pair <int, int> dir, gl::event_t event)
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
        _event = gl::Escape;
}

void arc::game::Pacman::manageEvent()
{
    if (_event == gl::Escape)
        return;
    else if (_event == gl::Left)
        checkMove({0, -1}, gl::Left);
    else if (_event == gl::Right)
        checkMove({0, 1}, gl::Right);
    else if (_event == gl::Up)
        checkMove({-1, 0}, gl::Up);
    else if (_event == gl::Down)
        checkMove({1, 0}, gl::Down);
    else if (_event == gl::Unknown)
        checkMove(_sDir, _eventP);
}
