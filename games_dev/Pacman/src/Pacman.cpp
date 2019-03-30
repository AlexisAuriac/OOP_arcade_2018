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

Pacman::Pacman()
{
    std::string line;
    std::ifstream mapFile("Pac_map/map1.txt");

    if (!mapFile) {
        std::cerr << "Error file" << std::endl;
        _map.push_back("NOP");
    } else {
        while (getline(mapFile, line))
            _map.push_back(line);
    }
    _time = 0;
    _score = 0;
    _sDir.first = 0;
    _sDir.second = 0;
    _eventP = arc::gl::Down;
    _event = arc::gl::Unknown;
}

void Pacman::init(arc::gl::IGraphicLib *gl)
{
    _gl = gl;
    if (_map[0] == "NOP")
        return;
    _posM.first = atoi(_map[0].c_str());
    _posM.second = atoi((_map[0].erase(0, _map[0].find(',') + 1)).c_str());
}

void Pacman::waitTurn()
{
    usleep(165000);
    ++_time;
}

void Pacman::gameRun()
{
    while (_event != arc::gl::Escape) {
        _event = _gl->getEvent();
        _gl->clear();
        drawMap();
        drawGhost();
        drawPerso();
        drawScore();
        _gl->display();
        waitTurn();
    }
}
