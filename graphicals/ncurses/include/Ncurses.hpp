/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for ncurses.
*/

#ifndef NCURES_HPP
#define NCURSES_HPP

#include "IGraphicLib.hpp"

namespace arc::gl {
    // class Ncurses {
    class Ncurses : public IGraphicLib {
        public:
            void openWindow() override;
            void closeWindow() override;
            // void openWindow();
            // void closeWindow();
    };
}

#endif