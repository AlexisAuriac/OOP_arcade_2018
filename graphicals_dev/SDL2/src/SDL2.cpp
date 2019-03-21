/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file of the SDL2 graphical library.
*/

#include <iostream>
#include "IGraphicLib.hpp"
#include "SDL2.hpp"

extern "C"
arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::SDL2();
}
