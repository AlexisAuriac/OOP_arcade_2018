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
    _posG[i].first += dir.first;
    _posG[i].second += dir.second;
}

void Pacman::manageGDir(arc::gl::event_t event, int i)
{
    if (event == arc::gl::Left)
        addPos(i, {-1, 0});
    if (event == arc::gl::Right)
        addPos(i, {1, 0});
    if (event == arc::gl::Up)
        addPos(i, {0, -1});
    if (event == arc::gl::Down)
        addPos(i, {0, 1});
    _sMov[i] = event;
}

void Pacman::porGDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    int random = rand() % nb_event.size();

    manageGDir(nb_event[random], i);
}

void Pacman::chooseDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    arc::gl::event_t erase_e;
    int poss = rand() % 100;

    if (_sMov[i] == arc::gl::Left || _sMov[i] == arc::gl::Right) {
        erase_e = arc::gl::Right;
        if (_sMov[i] == arc::gl::Right)
            erase_e = arc::gl::Left;
    } else {
        erase_e = arc::gl::Up;
        if (_sMov[i] == arc::gl::Up)
            erase_e = arc::gl::Down;
    }
    for (auto j = nb_event.begin() ; j != nb_event.end() ; ++j) {
        if (*j == erase_e) {
            nb_event.erase(j);
            break;
        }
    }
    if (poss <= 15 || nb_event.size() == 0) {
        if (_sMov[i] == arc::gl::Left || _sMov[i] == arc::gl::Right) {
            if (_sMov[i] == arc::gl::Right) {
                manageGDir(i, arc::gl::Left);
                return;
            }
            manageGDir(i, arc::gl::Right);
        } else {
            if (_sMov[i] == arc::gl::Up) {
                manageGDir(i, arc::gl::Down);
                return;
            }
            manageGDir(i, arc::gl::Up);
        }
    }
    else
        porGDir(i, nb_event);
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

    if (checkPos(_posG[i].second - 1, _posG[i].first) == true)
        nb_event.push_back(arc::gl::Up);
    if (checkPos(_posG[i].second + 1, _posG[i].first) == true)
        nb_event.push_back(arc::gl::Down);
    if (checkPos(_posG[i].second, _posG[i].first + 1) == true)
        nb_event.push_back(arc::gl::Right);
    if (checkPos(_posG[i].second, _posG[i].first - 1) == true)
        nb_event.push_back(arc::gl::Left);
    chooseDir(i, nb_event);
}

void Pacman::moveGhost(int i)
{
    arc::gl::event_t dir;

    if (_posG[i].first > 0 && _posG[i].first <= (_posM.first - 1)) {
        if ((_posG[i].first >= _door.first - 2 && _posG[i].first <= _door.first + 2)
            && (_posG[i].second >= _door.second && _posG[i].second < _door.second + 4)) {
            _posG[i].first = _door.first;
            _posG[i].second = _door.second - 1;
            dir = arc::gl::Right;
            if (rand()%100 >= 50)
                dir = arc::gl::Left;
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

void Pacman::drawGhost()
{
    std::vector<arc::gl::color_t> color = {arc::gl::GREEN, arc::gl::MAGENTA, arc::gl::GRAY, arc::gl::RED};

    if (_time > 60) {
        for (int i = 0; i < 4; ++i) {
            moveGhost(i);
            _gl->drawSquare(_posG[i].first, _posG[i].second, color[i]);
        }
        if (checkGhost() == false)
            _event = arc::gl::Escape;
    } else {
        for (int i = 0; i < 4; ++i)
            _gl->drawSquare(_posG[i].first, _posG[i].second, color[i]);
    }
}
