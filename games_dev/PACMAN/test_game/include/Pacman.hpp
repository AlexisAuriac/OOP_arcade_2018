/*
** EPITECH, 2018
** Pacman.hpp
** File description:
** Header Pacman for Library games.
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <vector>
#include <utility>
#include "IGraphicLib.hpp"

class Pacman
{
    private:// Ghost
        arc::gl::event_t _sMov;
        std::vector< std::pair <int, int> > _PosG;
        std::pair<int, int> _door;
    
    private:// Perso
        arc::gl::event_t _eventP;
        std::pair <int, int> _Pos;
        std::pair <int, int> _sDir;
    
    private:// Map
        arc::gl::event_t _event;
        std::pair <int, int> _posM;
        std::vector<std::string> _map;

    

    public:// Map
        Pacman();
        bool init();
        void gameRun(arc::gl::IGraphicLib *gl);
        void drawMap(arc::gl::IGraphicLib *gl);
        void drawScore(arc::gl::IGraphicLib *gl);
    
    public:// Perso
        void drawPerso(arc::gl::IGraphicLib *gl);
        void managEvent();
        bool checkGhost();
        void checkMov(std::pair <int, int> dir, arc::gl::event_t event);
        void movPerso(std::pair <int, int> dir, arc::gl::event_t event);
    
    public:// Ghost
        void drawGhost(arc::gl::IGraphicLib *gl);
        void movGhost(int i);
        void checkGDir(int i);
        void chooseDir(int i, std::vector<arc::gl::event_t> nb_event);
        void porGDir(int i, std::vector<arc::gl::event_t> nb_event);
        void managGDir(arc::gl::event_t event, int i);
        void addPos(int i, std::pair<int, int> dir);
};

#endif