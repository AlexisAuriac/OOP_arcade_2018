/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the interface for all graphic libraries.
*/

#ifndef IGRAPHIC_LIB_HPP
#define IGRAPHIC_LIB_HPP

#include <iostream>
#include <string>

namespace arc::gl {
    static const char ENTRY_POINT_NAME[] = "entryPoint";

    class IGraphicLib {
        public:
            virtual ~IGraphicLib() = default;
            virtual void openWindow() = 0;
            virtual void closeWindow() = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
            virtual int getCols() = 0;
            virtual int getLines() = 0;
            virtual void printText(const std::string &str, int col, int line) = 0;
    };
}

#endif
