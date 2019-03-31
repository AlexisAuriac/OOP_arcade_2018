/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a Nibbler game.
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <iostream>
#include <vector>
#include <utility>
#include "IGraphicLib.hpp"
#include "IGame.hpp"

namespace arc::game {
    class Nibbler : public IGame {
        public:
            void init(gl::IGraphicLib *gl) override;
            std::pair<state, int> play(gl::event_t event) override;
            void display() override;
            void restart() override;
            void changeGl(gl::IGraphicLib *gl) override;

        private:
            void posFruit(int flag);
            void manageHit();
            void moveSnake();
            void dirSnake(gl::event_t event);
            void manageEvent(gl::event_t event);

            void drawMap();
            void printScore();
            void printSnake();

        private:
            gl::IGraphicLib *_gl;
            int _row;
            int _col;
            int _run;
            int _index;
            int _movx;
            int _movy;
            std::pair<int, int> _fruit;
            std::vector<std::pair<int, int>> _tail;
            std::vector<std::pair<int, useconds_t>> _tabScore;
    };
}

#endif