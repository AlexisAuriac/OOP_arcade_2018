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
    private:
        // Ghost
        char _saveC;
        // Pacman
        int _run;
        arc::gl::event_t _sEvent;
        std::pair <int, int> _posM;
        std::pair <int, int> _posP;
        std::pair <int, int> _sDir;
        std::vector< std::pair <int, int> > _posG;
        std::vector<std::string> _map;
    // private:
    public:
        Pacman();
        bool init();
        bool checkGhost();
        void nb_dir(int i);
        void checkGDir(arc::gl::event_t event, int i);
        void movGhost(arc::gl::IGraphicLib *gl);
        void movGdir(std::pair<int, int> dir, arc::gl::event_t event, int i);
        void movGdir2(std::pair<int, int> dir, arc::gl::event_t event, int i);
        void gameRun(arc::gl::IGraphicLib *gl);
        bool managEvent(arc::gl::IGraphicLib *gl);
        void movPerso(std::pair <int, int> dir, arc::gl::event_t event);
        void drawMap(arc::gl::IGraphicLib *gl);
        void checkMov(std::pair <int, int> dir, arc::gl::event_t event);
};

#endif