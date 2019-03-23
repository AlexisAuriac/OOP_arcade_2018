/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a Nibbler games.
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

        private:
            void printSnake();
            void dirSnake(gl::event_t event);
            void moveSnake();
            void manageEvent(gl::event_t event);
            void drawMap();
            void manageHit();
            void posFruit(int flag);
            void printScore();

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