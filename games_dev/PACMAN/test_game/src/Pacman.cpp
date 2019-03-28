/*
** EPITECH, 2018
** Pacman.cpp
** File description:
** File Pacman for Library games.
*/

#include <iostream>
#include <unistd.h>
#include <fstream>
#include "Pacman.hpp"

Pacman::Pacman()
{
    std::string line;
    std::ifstream myflux("Pac_map/map1.txt");

    if (!myflux) {
        std::cerr << "Error file" << std::endl;
        _map.push_back("NOP");
    } else {
        while (getline(myflux, line))
            _map.push_back(line);
    }
    _time = 0;
    _score = 0;
    _sDir.first = 0;
    _sDir.second = 0;
    _eventP = arc::gl::Down;
    _event = arc::gl::Unknown;
}

bool Pacman::init()
{
    if (_map[0] == "NOP")
        return false;
    _posM.first = atoi(_map[0].c_str());
    _posM.second = atoi((_map[0].erase(0, _map[0].find(',') + 1)).c_str());
    return true;
}

void Pacman::my_time()
{
    usleep(165000);
    _time++;
}

void Pacman::gameRun(arc::gl::IGraphicLib *gl)
{
    srand(time(NULL));
 
    while (_event != arc::gl::Escape) {
        _event = gl->getEvent();
        gl->clear();
        this->drawMap(gl);
        this->drawGhost(gl);
        this->drawPerso(gl);
        this->drawScore(gl);
        gl->display();
        this->my_time();
    }
}