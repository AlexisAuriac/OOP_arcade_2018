/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main header.
*/

#ifndef ARCADE_HPP
#define ARCADE_HPP

#include <iostream>
#include <string>
#include "Error.hpp"
#include "IGraphicLib.hpp"
#include "DLLoaderLib.hpp"

namespace arc {
    static const int SUCCESS = 0;
    static const int FAILURE = 84;

    class Arcade {
    public:
        int run(int ac, char **av);

    private:
        void handleArgumentErrors(int ac, char **av);
        void loadInitLib(const std::string &libName);

    private:
        DLLoader<gl::IGraphicLib> _glLoader;
        gl::IGraphicLib *_gl;
        // DLLoader<game::Igame> _gameLoader;
        // game::IGame *_game;
    };
}

#endif
