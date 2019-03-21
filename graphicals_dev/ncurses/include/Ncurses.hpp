/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for ncurses.
*/

#ifndef NCURES_HPP
#define NCURSES_HPP

#include <string>
#include "IGraphicLib.hpp"

namespace arc::gl {
    class Ncurses : public IGraphicLib {
        public:
            void openWindow() override;
            void closeWindow() override;
            void display() override;
            void clear() override;
            int getCols() override;
            int getLines() override;
            void printText(const std::string &str, int col, int line) override;
    };
}

#endif