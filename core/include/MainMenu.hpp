/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the MainMenu class.
*/

#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Error.hpp"
#include "IGraphicLib.hpp"
#include "DLLoaderLib.hpp"

namespace arc {
    class MainMenu {
    public:
        enum action {
            NOTHING,
            MOVE,
            SELECT_GL,
            SELECT_GAME
        };

        void init(
            gl::IGraphicLib *gl,
            std::vector<std::string> &gls,
            std::vector<std::string> &games);
        void changeLib(gl::IGraphicLib *gl);
        bool HandleMove(gl::event_t event);
        std::pair<action, const std::string> handleEvent(gl::event_t event);
        void display();

    private:
        void displayList(
            unsigned int nbList,
            const std::string &listName,
            std::vector<std::string> entries,
            int col);

    private:
        std::pair<unsigned int, unsigned int> _pos;

        gl::IGraphicLib *_gl = nullptr;

        std::vector<std::string> _games;
        std::vector<std::string> _gls;
    };
}

#endif
