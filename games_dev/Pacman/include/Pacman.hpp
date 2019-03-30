/*
** EPITECH, 2018
** arcade
** File description:
** Header Pacman for Library games.
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <vector>
#include <utility>
#include "IGraphicLib.hpp"

class Pacman {
public:// Map
    Pacman();
    void init(arc::gl::IGraphicLib *gl);
    void waitTurn();
    void gameRun();
    void drawMap();
    void drawScore();

public:// Perso
    void drawPerso();
    void manageEvent();
    bool checkGhost();
    void checkMove(std::pair<int, int> dir, arc::gl::event_t event);
    void movPerso(std::pair<int, int> dir, arc::gl::event_t event);

public:// Ghost
    void drawGhost();
    void moveGhost(int i);
    void checkGDir(int i);
    bool checkPos(int x, int y);
    void chooseDir(int i, std::vector<arc::gl::event_t> nb_event);
    void porGDir(int i, std::vector<arc::gl::event_t> nb_event);
    void manageGDir(arc::gl::event_t event, int i);
    void addPos(int i, std::pair<int, int> dir);

private:// Ghost
    int _time;
    std::vector<arc::gl::event_t> _sMov;
    std::vector<std::pair<int, int>> _posG;
    std::pair<int, int> _door;

private:// Perso
    arc::gl::event_t _eventP;
    std::pair<int, int> _pos;
    std::pair<int, int> _sDir;

private:// Map
    arc::gl::IGraphicLib *_gl;
    arc::gl::event_t _event;
    std::pair<int, int> _posM;
    std::vector<std::string> _map;
    int _score;
};

#endif
