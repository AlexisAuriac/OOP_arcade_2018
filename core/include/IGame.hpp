/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the interface for all games.
*/

#ifndef IGRAPHIC_GAME_HPP
#define IGRAPHIC_GAME_HPP

#include <utility>
#include "IGraphicLib.hpp"

namespace arc::game {
    static const char ENTRY_POINT_NAME[] = "entryPoint";

    enum state {
        PLAYING,
        OVER
    };

    class IGame {
        public:
            virtual ~IGame() = default;
            virtual void init(gl::IGraphicLib *gl) = 0;
            // virtual void init(gl::IGraphicLib &*gl) = 0;
            virtual std::pair<state, int> play(gl::event_t event) = 0;
            virtual void display() = 0;
            virtual void restart() = 0;
            // virtual void changeGl(gl::IGraphicLib *gl) = 0;
    };
}

#endif
