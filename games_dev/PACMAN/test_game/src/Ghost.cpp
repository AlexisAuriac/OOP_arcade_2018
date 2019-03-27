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
        this->addPos(i, {0, -1});
    if (event == arc::gl::Right)
        this->addPos(i, {0, -1});
    if (event == arc::gl::Up)
        this->addPos(i, {-1, 0});
    if (event == arc::gl::Down)
        this->addPos(i, {1, 0});
}

void Pacman::porGDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    std::vector<float> list_e;
    float por = 100 / (float)nb_event.size();
    int random = rand()%(100 - 0) + 0;
    int l = 0;

    list_e.push_back(1);
    for (int j = 1; j < (int)nb_event.size(); j++)
        list_e.push_back(list_e[j - 1] + por);
    for (int l = 0; l < (int)list_e.size();) {
        if (random >= list_e[l])
            l++;
        else {
            l--;
            this->managGDir(nb_event[l], i);
            break;
        }
    }
    this->managGDir(nb_event[l], i);
}

void Pacman::chooseDir(int i, std::vector<arc::gl::event_t> nb_event)
{
    // int flag = 0;
    arc::gl::event_t erase_e;

    // if (_sMov == arc::gl::Left || _sMov == arc::gl::Right) {
    //     erase_e = arc::gl::Right;
    //     if (_sMov == arc::gl::Right)
    //         erase_e = arc::gl::Left;
    // } else {
    //     erase_e = arc::gl::Up;
    //     if (_sMov == arc::gl::Up)
    //         erase_e = arc::gl::Down;
    // }
    for (auto j = nb_event.begin(); j != nb_event.end(); ++j) {
        if (*j == _sMov) {
            // flag = 1;
            nb_event.erase(j);
            break;
        }
    }
    // if (flag == 1) {
    //     int poss = rand()%(100 - 0) + 0;
    //     if (poss < 15)
    //         if (_sMov == arc::gl::Left || _sMov == arc::gl::Right) {
    //             if (_sMov == arc::gl::Right) {
    //                 this->managGDir(i, arc::gl::Left);
    //                 return;
    //             }
    //             this->managGDir(i, arc::gl::Right);
    //         } else {
    //             if (_sMov == arc::gl::Up) {
    //                 this->managGDir(i, arc::gl::Down);
    //                 return;
    //             }
    //             this->managGDir(i, arc::gl::Up);
    //         }
    //     else
    //         this->porGDir(i, nb_event);
    // }
    // else
    this->porGDir(i, nb_event);
}

void Pacman::checkGDir(int i)
{
    std::vector<arc::gl::event_t> nb_event;

    if (_map[_PosG[i].second + 1][_PosG[i].first] != 'X'
        && _map[_PosG[i].second + 1][_PosG[i].first] != '-')
        nb_event.push_back(arc::gl::Up);
    if (_map[_PosG[i].second - 1][_PosG[i].first] != 'X'
        && _map[_PosG[i].second - 1][_PosG[i].first] != '-')
        nb_event.push_back(arc::gl::Down);
    if (_map[_PosG[i].second][_PosG[i].first + 1] != 'X'
        && _map[_PosG[i].second][_PosG[i].first + 1] != '-')
        nb_event.push_back(arc::gl::Right);
    if (_map[_PosG[i].second][_PosG[i].first - 1] != 'X'
        && _map[_PosG[i].second][_PosG[i].first - 1] != '-')
        nb_event.push_back(arc::gl::Left);
    this->chooseDir(i, nb_event);
}

void Pacman::movGhost(int i)
{
    if (_PosG[i].first > 0 && _PosG[i].first < (_posM.first - 1)) {
        if ((_PosG[i].first > _door.first - 3 && _PosG[i].first < _door.first)
            && (_PosG[i].second > _door.second - 2 && _PosG[i].second < _door.second + 2)) {
            _PosG[i].first = _door.first;
            _PosG[i].second = _door.second - 1;
            _sMov = arc::gl::Right;
        }
        else
            this->checkGDir(i);
    }
}

void Pacman::drawGhost(arc::gl::IGraphicLib *gl)
{
    std::vector<arc::gl::color_t> color = {arc::gl::GREEN, arc::gl::MAGENTA, arc::gl::GRAY, arc::gl::RED};

    this->movGhost(0);
    gl->drawSquare(_PosG[0].first, _PosG[0].second, color[0]);    
    // for (int i = 0; i < 4; i++)
    //     gl->drawSquare(_PosG[i].first, _PosG[i].second, color[i]);
}