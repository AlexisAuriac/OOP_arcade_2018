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
        std::vector< std::pair <int, int> > _tail;
        void print_snake(arc::gl::IGraphicLib *gl);
    public:
        Nibbler(arc::gl::IGraphicLib *gl);
        ~Nibbler();
        void gameRun(arc::gl::IGraphicLib *gl);
        void move_snake();
        // void print_snake();
};

#endif