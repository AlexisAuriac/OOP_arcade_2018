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
            virtual void openWindow() = 0;
            virtual void closeWindow() = 0;
    };
}

#endif
