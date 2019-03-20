/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for SDL2.
*/

#ifndef SLD2_HPP
#define SLD2_HPP

#include "IGraphicLib.hpp"

namespace arc::gl {
    class SDL2 : public IGraphicLib {
    public:
        SDL2();
        ~SDL2();
    };
}

#endif
