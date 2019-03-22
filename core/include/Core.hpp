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
#include <list>
#include "Error.hpp"
#include "IGraphicLib.hpp"
#include "DLLoaderLib.hpp"

namespace arc {
    static const int SUCCESS = 0;
    static const int FAILURE = 84;

    static const char GAMES_DIR[] = "./games";
    static const char GLS_DIR[] = "./graphicals";

    class Core {
    public:
        ~Core();

        int run(int ac, char **av);


    private:
        void handleArgumentErrors(int ac, char **av);

        void ReadLibDir(const char *dirName, std::list<std::string> &fList);
        void getAssets();
        std::string trimPath(const std::string &libName) noexcept;
        void init(const std::string &libName);

        void displayMenu(
            const std::string &listName,
            std::list<std::string> entries,
            int col,
            int curX,
            int curY);
        void mainMenu();

    private:
        std::string _currGl;

        DLLoader<gl::IGraphicLib> _glLoader;
        gl::IGraphicLib *_gl = nullptr;
        // DLLoader<game::Igame> _gameLoader;
        // game::IGame *_game;

        std::list<std::string> _games;
        std::list<std::string> _gls;
    };
}

#endif
