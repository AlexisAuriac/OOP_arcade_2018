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
    _run = 1;
    _sDir.first = 0;
    _sDir.second = 0;
    _sEvent = arc::gl::Down;
}

bool Pacman::init()
{
    if (_map[0] == "NOP")
        return false;
    _posM.first = atoi(_map[0].c_str());
    _posM.second = atoi((_map[0].erase(0, _map[0].find(',') + 1)).c_str());
    return true;
}

void Pacman::movPerso(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (event == arc::gl::Right || event == arc::gl::Left) {
        if (_map[_posP.second][_posP.first + dir.second] != 'X') {
            _sDir = dir;
            _sEvent = event;
            _map[_posP.second][_posP.first] = ' ';
            _posP.first += dir.second;
            _map[_posP.second][_posP.first] = 'C';            
        }
    } else {
        if (_map[_posP.second + dir.first][_posP.first] != 'X') {
            _map[_posP.second][_posP.first] = ' ';
            _sDir = dir;
            _sEvent = event;
            _posP.second += dir.first;
            _map[_posP.second][_posP.first] = 'C';
        }
    }
}

bool Pacman::checkGhost()
{
    for (int i = 0; i < 4; i++) {
        if (_posP == _posG[i])
            return false;
    }
    return true;
}

void Pacman::checkMov(std::pair <int, int> dir, arc::gl::event_t event)
{
    if (_posP.first > 0 && _posP.first < (_posM.first - 1)) {
        if (this->checkGhost() == false){
            _run = 0;
            return;
        }
        movPerso(dir, event);
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

std::pair<int, int> addPair(std::pair<int, int> p1, std::pair<int, int> p2)
{
    std::pair<int, int> dest(p1);

    dest.first += p2.first;
    dest.second += p2.second;
    return dest;
}

void Pacman::movGdir2(std::pair<int, int> dir, arc::gl::event_t event, int i)
{
    if (event == arc::gl::Right || event == arc::gl::Left) {    
        if (_map[_posG[i].second][_posG[i].first + dir.second] != 'X'
            && _map[_posG[i].second][_posG[i].first + dir.second] != '8') {
            if (_map[_posG[i].second][_posG[i].first + dir.second] == '*')
                
            _posP.first += dir.second;
            _map[_posP.second][_posP.first] = 'C';            
        }
    } else {
        if (_map[_posP.second + dir.first][_posP.first] != 'X') {
            _map[_posP.second][_posP.first] = ' ';
            _posP.second += dir.first;
            _map[_posP.second][_posP.first] = 'C';
        }
    }
}

void Pacman::movGdir(std::pair<int, int> dir, arc::gl::event_t event, int i)
{
    if (_posG[i].first > 0 && _posG[i].first < (_posM.first - 1)) {
        this->movGdir2(dir, event, i);
    }
    // } else {
    //     _map[_posG[i].second][_posG[i].first] = ' ';
    //     if (_posP.first <= 0) {
    //         _map[_posP.second][_posM.first - 1] = ' ';
    //         _posP.first = _posM.first - 2;
    //     } else if (_posP.first >= _posM.first - 1) {
    //         _map[_posP.second][0] = ' ';
    //         _posP.first = 1;
    //     }
    //     _map[_posP.second][_posP.first] = 'C';
    // }
}

void Pacman::checkGDir(arc::gl::event_t event, int i)
{
    if (event == arc::gl::Left)
        this->movGdir({0, -1}, arc::gl::Left, i);
    if (event == arc::gl::Right)
        this->movGdir({0, 1}, arc::gl::Right, i);
    if (event == arc::gl::Up)
        this->movGdir({-1, 0}, arc::gl::Up, i);
    if (event == arc::gl::Down)
        this->movGdir({1, 0}, arc::gl::Down, i);
}

void Pacman::nb_dir(int i)
{
    std::vector<arc::gl::event_t> saveDir;
    std::pair<int, int> saveP;

    saveP = addPair(_posG[i], {0, -1});
    if (_map[saveP.first][saveP.second] != 'X'
        && _map[saveP.first][saveP.second] != '8')
        saveDir.push_back(arc::gl::Up);
    saveP = addPair(_posG[i], {0, 1});
    if (_map[saveP.first][saveP.second] != 'X'
        && _map[saveP.first][saveP.second] != '8')
        saveDir.push_back(arc::gl::Down);
    saveP = addPair(_posG[i], {1, 0});
    if (_map[saveP.first][saveP.second] != 'X'
        && _map[saveP.first][saveP.second] != '8')
        saveDir.push_back(arc::gl::Right);
    saveP = addPair(_posG[i], {-1, 0});
    if (_map[saveP.first][saveP.second] != 'X'
        && _map[saveP.first][saveP.second] != '8')
        saveDir.push_back(arc::gl::Left);
    std::vector<float> tabPorc;
    tabPorc.push_back(0);
    for (int l = 1; l < (int)(saveDir.size() - 1); l++)
        tabPorc.push_back((tabPorc[l - 1]) + (100 / saveDir.size()));
    float random = rand()%(100 - 0) + 0;
    for (int j = 0; j < (int)tabPorc.size(); j++) {
        if (tabPorc[j] >= random && tabPorc[j + 1] < random)
            this->checkGDir(saveDir[j], i);
            return;
    }
}

void Pacman::movGhost(arc::gl::IGraphicLib *gl)
{
    std::vector <arc::gl::color_t> color = {arc::gl::GREEN, arc::gl::RED, arc::gl::MAGENTA, arc::gl::GRAY};
    
    for (int i = 0; i < 4; i++)
        gl->drawSquare(_posG[i].first, _posG[i].second, color[i]);
    for (int i = 0; i < 4; i++) {
        this->nb_dir(i);
    }
}

bool Pacman::managEvent(arc::gl::IGraphicLib *gl)
{
    arc::gl::event_t event = gl->getEvent();

    if (event == arc::gl::Escape)
        return false;
    else if (event == arc::gl::Left)
        this->checkMov({0, -1}, arc::gl::Left);
    else if (event == arc::gl::Right)
        this->checkMov({0, 1}, arc::gl::Right);
    else if (event == arc::gl::Up)
        this->checkMov({-1, 0}, arc::gl::Up);
    else if (event == arc::gl::Down)
        this->checkMov({1, 0}, arc::gl::Down);
    else if (event == arc::gl::Unknown)
        this->checkMov(_sDir, _sEvent);
    usleep(100000);
    return true;
}

void Pacman::drawMap(arc::gl::IGraphicLib *gl)
{
    for (int x = 1; x <= _posM.first + 1; x++) {
        for (int y = 0; y < _posM.second; y++) {
            if (_map[x][y] == 'X')
                gl->drawSquare(y, x, arc::gl::BLUE);
            else if (_map[x][y] == '.' || _map[x][y] == '*') {
                arc::gl::textParams_t text;
                text.x = y;
                text.y = x;
                gl->printText((_map[x][y] == '.') ? "." : "*", text);
            } else if (_map[x][y] == 'C') {
                gl->drawSquare(y, x, arc::gl::YELLOW);
                _posP.first = y;
                _posP.second = x;
            }
            else if (_map[x][y] == 'G')
                _posG.push_back(std::make_pair(y, x));
        }
    }
}

void Pacman::gameRun(arc::gl::IGraphicLib *gl)
{
    srand(time(NULL));
    while (_run) {
        gl->clear();
        this->drawMap(gl);
        if (managEvent(gl) == false)
            return;
        this->movGhost(gl);
        gl->display();
    }
}