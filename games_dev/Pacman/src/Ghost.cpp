/*
** EPITECH, 2018
** drawPerso.cpp
** File description:
** File Pacman for Library games.
*/

#include <stdlib.h>
#include <time.h>
#include "Pacman.hpp"

void arc::game::Pacman::addPos(int i, std::pair<int, int> dir)
{
    _posG[i].first += dir.first;
    _posG[i].second += dir.second;
}

void arc::game::Pacman::manageGDir(gl::event_t event, int i)
{
    if (event == gl::Left)
        addPos(i, {-1, 0});
    if (event == gl::Right)
        addPos(i, {1, 0});
    if (event == gl::Up)
        addPos(i, {0, -1});
    if (event == gl::Down)
        addPos(i, {0, 1});
    _sMov[i] = event;
}

void arc::game::Pacman::porGDir(int i, std::vector<gl::event_t> nbEvent)
{
    int random = rand() % nbEvent.size();

    manageGDir(nbEvent[random], i);
}

void arc::game::Pacman::chooseDir(int i, std::vector<gl::event_t> nbEvent)
{
    gl::event_t erase_e;
    int poss = rand() % 100;

    if (_sMov[i] == gl::Left || _sMov[i] == gl::Right) {
        erase_e = gl::Right;
        if (_sMov[i] == gl::Right)
            erase_e = gl::Left;
    } else {
        erase_e = gl::Up;
        if (_sMov[i] == gl::Up)
            erase_e = gl::Down;
    }
    for (auto j = nbEvent.begin() ; j != nbEvent.end() ; ++j) {
        if (*j == erase_e) {
            nbEvent.erase(j);
            break;
        }
    }
    if (poss <= 15 || nbEvent.size() == 0) {
        if (_sMov[i] == gl::Left || _sMov[i] == gl::Right) {
            if (_sMov[i] == gl::Right) {
                manageGDir(i, gl::Left);
                return;
            }
            manageGDir(i, gl::Right);
        } else {
            if (_sMov[i] == gl::Up) {
                manageGDir(i, gl::Down);
                return;
            }
            manageGDir(i, gl::Up);
        }
    }
    else
        porGDir(i, nbEvent);
}

bool arc::game::Pacman::checkPos(int x, int y)
{
    if (_map[x][y] == 'X')
        return false;
    if (_map[x][y] == '-')
        return false;
    return true;
}

void arc::game::Pacman::checkGDir(int i)
{
    std::vector<gl::event_t> nbEvent;

    if (checkPos(_posG[i].second - 1, _posG[i].first) == true)
        nbEvent.push_back(gl::Up);
    if (checkPos(_posG[i].second + 1, _posG[i].first) == true)
        nbEvent.push_back(gl::Down);
    if (checkPos(_posG[i].second, _posG[i].first + 1) == true)
        nbEvent.push_back(gl::Right);
    if (checkPos(_posG[i].second, _posG[i].first - 1) == true)
        nbEvent.push_back(gl::Left);
    chooseDir(i, nbEvent);
}

void arc::game::Pacman::moveGhost(int i)
{
    gl::event_t dir;

    if (_posG[i].first > 0 && _posG[i].first <= (_posM.first - 1)) {
        if ((_posG[i].first >= _door.first - 2 && _posG[i].first <= _door.first + 2)
            && (_posG[i].second >= _door.second && _posG[i].second < _door.second + 4)) {
            _posG[i].first = _door.first;
            _posG[i].second = _door.second - 1;
            dir = gl::Right;
            if (rand() % 100 >= 50)
                dir = gl::Left;
            _sMov.push_back(dir);
        }
        else
            checkGDir(i);
    } else {
        if (_posG[i].first == 0)
            _posG[i].first = _posM.first - 1;
        else
            _posG[i].first = 1;
    }
}

void arc::game::Pacman::moveGhosts()
{
    if (time(NULL) - _start > 10) {
        for (int i = 0; i < 4; ++i)
            moveGhost(i);
        if (!checkGhost())
            _state = OVER;
    }
}

void arc::game::Pacman::drawGhost()
{
    std::vector<gl::color_t> colors = {
        gl::GREEN,
        gl::MAGENTA,
        gl::GRAY,
        gl::RED
    };

    for (int i = 0; i < 4; ++i)
        _gl->drawSquare(_posG[i].first, _posG[i].second, colors[i]);
}
