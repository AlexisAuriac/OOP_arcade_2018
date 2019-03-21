/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for ncurses.
*/

#ifndef NCURES_HPP
#define NCURSES_HPP

#include <string>
#include <ncurses.h>
#include "IGraphicLib.hpp"

namespace arc::gl {
    class Ncurses : public IGraphicLib {
        const int CONNECT_COLORS[NB_COLORS] = {
            [BLACK] = COLOR_BLACK,
            [BLUE] = COLOR_BLUE,
            [GREEN] = COLOR_GREEN,
            [CYAN] = COLOR_CYAN,
            [RED] = COLOR_RED,
            [MAGENTA] = COLOR_MAGENTA,
            [WHITE] = COLOR_WHITE + 8,
            [GRAY] = COLOR_WHITE,
            [YELLOW] = COLOR_YELLOW,
        };

        public:
            void openWindow() override;
            void closeWindow() override;
            void display() override;
            void clear() override;
            int getCols() override;
            int getLines() override;
            void printText(
                const std::string &str,
                const textParams_t &params) override;
    };
}

#endif