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
#include <vector>
#include "Error.hpp"
#include "IGraphicLib.hpp"
#include "DLLoaderLib.hpp"
#include "IGame.hpp"
#include "DLLoaderGame.hpp"
#include "MainMenu.hpp"

namespace arc {
    static const int SUCCESS = 0;
    static const int FAILURE = 84;

    static const char GAMES_DIR[] = "./games/";
    static const char GLS_DIR[] = "./graphicals/";

    class Core {
        typedef enum {
            IN_MENU,
            IN_GAME,
            OVER
        } states_t;

    public:
        ~Core();

        int run(int ac, char **av);

    private:
        void handleArgumentErrors(int ac, char **av);

        void readLibDir(const char *dirName, std::vector<std::string> &fList);
        void getAssets();
        void init(const std::string &libName);

        bool handleEvent(gl::event_t event);
        void alert(const std::string &str);
        void playMenu(gl::event_t event);
        void playGame(gl::event_t event);
        void mainLoop();

    private:
        MainMenu _menu;

        states_t _state = IN_MENU;

        DLLoader<gl::IGraphicLib> _glLoader;
        gl::IGraphicLib *_gl = nullptr;
        DLLoader<game::IGame> _gameLoader;
        game::IGame *_game = nullptr;

        std::vector<std::string> _games;
        std::vector<std::string> _gls;
    };
}

#endif
