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
        std::pair <int, int> _posM;
        std::pair <int, int> _posP;
        std::vector<std::string> _map;
    public:
        Pacman();
        bool init(arc::gl::IGraphicLib *gl);
        void gameRun(arc::gl::IGraphicLib *gl);
        bool managEvent(arc::gl::IGraphicLib *gl);
        void movPerso(int dir, arc::gl::event_t event);
        void drawMap(arc::gl::IGraphicLib *gl);
};

#endif