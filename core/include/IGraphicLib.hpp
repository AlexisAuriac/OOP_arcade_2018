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

    enum {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        WHITE,
        GRAY,
        YELLOW,
        NB_COLORS
    };

    typedef int color_t;

    typedef struct textParams {
        short x;
        short y;
        color_t colorFg : 4;
        color_t colorBg : 4;
        bool bold : 1;

        textParams(
            int x = 0,
            int y = 0,
            int fg = WHITE,
            int bg = BLACK,
            bool bold = false)
        : x(x), y(y), colorFg(fg), colorBg(bg), bold(bold)
        {}
    } textParams_t;

    class IGraphicLib {
        public:
            virtual ~IGraphicLib() = default;
            virtual void openWindow() = 0;
            virtual void closeWindow() = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
            virtual int getCols() = 0;
            virtual int getLines() = 0;
            virtual void printText(
                const std::string &str,
                const textParams_t &params) = 0;
    };
}

#endif
