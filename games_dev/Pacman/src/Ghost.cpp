/*
** EPITECH, 2018
** drawPerso.cpp
** File description:
** File Pacman for Library games.
*/

#include <stdlib.h>
#include <time.h>
#include "Pacman.hpp"

void Pacman::addPos(int i, std::pair<int, int> dir)
{
    _PosG[i].first += dir.first;
    _PosG[i].second += dir.second;
}

void Pacman::managGDir(arc::gl::event_t event, int i)
{
    if (event == arc::gl::Left)
        this->addPos(i, {-1, 0});
    if (event == arc::gl::Right)
        this->addPos(i, {1, 0});
    if (event == arc::gl::Up)
        this->addPos(i, {0, -1});
    if (event == arc::gl::Down)
        this->addPos(i, {0, 1});
    _sMov[i] = event;
}

void Pacman::porGDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    int random = rand()%nb_event.size();

    this->managGDir(nb_event[random], i);
}

void Pacman::chooseDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    arc::gl::event_t erase_e;

    if (_sMov[i] == arc::gl::Left || _sMov[i] == arc::gl::Right) {
        erase_e = arc::gl::Right;
        if (_sMov[i] == arc::gl::Right)
            erase_e = arc::gl::Left;
    } else {
        erase_e = arc::gl::Up;
        if (_sMov[i] == arc::gl::Up)
            erase_e = arc::gl::Down;
    }
    for (auto j = nb_event.begin(); j != nb_event.end(); ++j) {
        if (*j == erase_e) {
            nb_event.erase(j);
            break;
        }
    }
    int poss = rand()%(100 - 0) + 0;
    if (poss <= 15 || nb_event.size() == 0) {
        if (_sMov[i] == arc::gl::Left || _sMov[i] == arc::gl::Right) {
            if (_sMov[i] == arc::gl::Right) {
                this->managGDir(i, arc::gl::Left);
                return;
            }
            this->managGDir(i, arc::gl::Right);
        } else {
            if (_sMov[i] == arc::gl::Up) {
                this->managGDir(i, arc::gl::Down);
                return;
            }
            this->managGDir(i, arc::gl::Up);
        }
    }
    else
        this->porGDir(i, nb_event);
}

bool Pacman::checkPos(int x, int y)
{
    if (_map[x][y] == 'X')
        return false;
    if (_map[x][y] == '-')
        return false;
    return true;
}

void Pacman::checkGDir(int i)
{
    std::vector<arc::gl::event_t> nb_event;

    if (this->checkPos(_PosG[i].second - 1, _PosG[i].first) == true)
        nb_event.push_back(arc::gl::Up);
    if (this->checkPos(_PosG[i].second + 1, _PosG[i].first) == true)
        nb_event.push_back(arc::gl::Down);
    if (this->checkPos(_PosG[i].second, _PosG[i].first + 1) == true)
        nb_event.push_back(arc::gl::Right);
    if (this->checkPos(_PosG[i].second, _PosG[i].first - 1) == true)
        nb_event.push_back(arc::gl::Left);
    this->chooseDir(i, nb_event);
}

void Pacman::movGhost(int i)
{
    arc::gl::event_t dir;

    if (_PosG[i].first > 0 && _PosG[i].first <= (_posM.first - 1)) {
        if ((_PosG[i].first >= _door.first - 2 && _PosG[i].first <= _door.first + 2)
            && (_PosG[i].second >= _door.second && _PosG[i].second < _door.second + 4)) {
            _PosG[i].first = _door.first;
            _PosG[i].second = _door.second - 1;
            dir = arc::gl::Right;
            if (rand()%100 >= 50)
                dir = arc::gl::Left;
            _sMov.push_back(dir);
        }
        else
            this->checkGDir(i);
    } else {
        if (_PosG[i].first == 0)
            _PosG[i].first = _posM.first - 1;
        else
            _PosG[i].first = 1;
    }
}

void Pacman::drawGhost(arc::gl::IGraphicLib *gl)
{
    std::vector<arc::gl::color_t> color = {arc::gl::GREEN, arc::gl::MAGENTA, arc::gl::GRAY, arc::gl::RED};

    if (_time > 60) {
        for (int i = 0; i < 4; ++i) {
            this->movGhost(i);
            gl->drawSquare(_PosG[i].first, _PosG[i].second, color[i]);
        }
        if (this->checkGhost() == false)
            _event = arc::gl::Escape;
    } else {
        for (int i = 0; i < 4; ++i)
            gl->drawSquare(_PosG[i].first, _PosG[i].second, color[i]);
    }
}