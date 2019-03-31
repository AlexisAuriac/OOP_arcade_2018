/*
** EPITECH, 2018
** Pacman.cpp
** File description:
** File Pacman for Library games.
*/

#include <iostream>
#include <unistd.h>
#include <fstream>
#include "IGraphicLib.hpp"
#include "Pacman.hpp"

bool arc::game::Pacman::loadMap()
{
    std::string line;
    std::ifstream mapFile("assets/pacman_map.txt");

    if (!mapFile) {
        std::cerr << "Error file" << std::endl;
        return false;
    } else {
        while (getline(mapFile, line))
            _map.push_back(line);
    }
    return true;
}

void arc::game::Pacman::init(gl::IGraphicLib *gl)
{
    if (!loadMap())
        return;
    _gl = gl;
    _state = PLAYING;
    _posM.first = atoi(_map[0].c_str());
    _posM.second = atoi((_map[0].erase(0, _map[0].find(',') + 1)).c_str());
    _start = time(nullptr);
    _lastTurn = clock();
    _drawable = false;
    _score = 0;
    _sDir.first = 0;
    _sDir.second = 0;
    _eventP = gl::Down;
}

void arc::game::Pacman::restart()
{
    init(_gl);
}

std::pair<arc::game::state, int> arc::game::Pacman::play(gl::event_t event)
{
    if (event != gl::Unknown)
        _event = event;
    if ((clock() - _lastTurn) * 10 / CLOCKS_PER_SEC) {
        updateMap();
        moveGhosts();
        manageEvent();
        _lastTurn = clock();
        _drawable = true;
    }
    return std::make_pair(_state, 0);
}

void arc::game::Pacman::display()
{
    if (!_drawable)
        return;
    _gl->clear();
    drawMap();
    drawGhost();
    drawPerso();
    drawScore();
    _gl->display();
    _drawable = false;
}

void arc::game::Pacman::changeGl(gl::IGraphicLib *gl)
{
    _gl = gl;
}

extern "C" arc::game::IGame *entryPoint()
{
    return new arc::game::Pacman();
}
