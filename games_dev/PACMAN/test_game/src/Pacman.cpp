/*
** EPITECH, 2018
** Pacman.cpp
** File description:
** File Pacman for Library games.
*/

#include <iostream>
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
}

bool Pacman::init(arc::gl::IGraphicLib *gl)
{
    if (_map[0] == "NOP")
        return false;
    _posM.first = atoi(_map[0].c_str());
    _posM.second = atoi((_map[0].erase(0, _map[0].find(',') + 1)).c_str());
    return true;
}

void Pacman::movPerso(int dir, arc::gl::event_t event)
{
    if ((_posP.first > 0 && _posP.first < _posM.first - 1)) {
        if (event == arc::gl::Right || event == arc::gl::Left) {
            if (_map[_posP.second][_posP.first + dir] != 'X') {
                _map[_posP.second][_posP.first] = ' ';
                _posP.first += dir;
                _map[_posP.second][_posP.first] = 'C';            
            }
        } else {
            if (_map[_posP.second + dir][_posP.first] != 'X') {
                _map[_posP.second][_posP.first] = ' ';
                _posP.second += dir;
                _map[_posP.second][_posP.first] = 'C';
            }
        }
    } else {
        _map[_posP.second][_posP.first] = ' ';
        if (_posP.first <= 0) {
            _map[_posP.second][_posM.first - 1] = ' ';
            _posP.first = _posM.first - 2;
        } else if (_posP.first >= _posM.first - 1) {
            _map[_posP.second][0] = ' ';
            _posP.first = 1;
        }
        _map[_posP.second][_posP.first] = 'C';
    }
}

bool Pacman::managEvent(arc::gl::IGraphicLib *gl)
{
    arc::gl::event_t event = gl->getEvent();

    if (event == arc::gl::Escape)
        return false;
    else if (event == arc::gl::Left)
        this->movPerso(-1, arc::gl::Left);
    else if (event == arc::gl::Right)
        this->movPerso(1, arc::gl::Right);
    else if (event == arc::gl::Up)
        this->movPerso(-1, arc::gl::Up);
    else if (event == arc::gl::Down)
        this->movPerso(1, arc::gl::Down);
    return true;
}

void Pacman::gameRun(arc::gl::IGraphicLib *gl)
{
    while (1) {
        gl->clear();
        this->drawMap(gl);
        gl->display();
        if (managEvent(gl) == false)
            return;
    }
}

void Pacman::drawMap(arc::gl::IGraphicLib *gl)
{
    for (int x = 1; x <= _posM.first + 1; x++) {
        for (int y = 0; y < _posM.second; y++) {
            if (_map[x][y] == 'X')
                gl->drawSquare(y, x, arc::gl::BLUE);
            else if (_map[x][y] == '.') {
                arc::gl::textParams_t text;
                text.x = y;
                text.y = x;
                gl->printText(".", text);
            }
            else if (_map[x][y] == 'C') {
                gl->drawSquare(y, x, arc::gl::YELLOW);
                _posP.first = y;
                _posP.second = x;
            }
        }
    }
}