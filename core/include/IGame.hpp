/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the interface for all games.
*/

#ifndef IGRAPHIC_GAME_HPP
#define IGRAPHIC_GAME_HPP

namespace arc::game {
    static const char ENTRY_POINT_NAME[] = "entryPoint";

    class IGame {
        public:
            virtual ~IGame() = default;
    };
}

#endif
