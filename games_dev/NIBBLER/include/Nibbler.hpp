/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a Nibbler games.
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <iostream>
#include <vector>
#include <utility>
#include "IGraphicLib.hpp"

class Nibbler
{
    private:
        int _row;
        int _col;
        int _run;
        int _index;
        int _movx;
        int _movy;
        std::pair <int, int> _fruit;
        std::vector< std::pair <int, int> > _tail;
        std::vector< std::pair <int, useconds_t> > _tabScore;
    private:
        void print_snake(arc::gl::IGraphicLib *gl);
        void dir_snake(arc::gl::event_t event);
        void move_snake();
        bool manag_event(arc::gl::IGraphicLib *gl);
        void drawMap(arc::gl::IGraphicLib *gl);
        void manag_hit();
        void posFruit(int flag);
        void printScore(arc::gl::IGraphicLib *gl);
    public:
        Nibbler(arc::gl::IGraphicLib *gl);
        void gameRun(arc::gl::IGraphicLib *gl);
};

#endif