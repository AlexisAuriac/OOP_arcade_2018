/*
** EPITECH, 2018
** arcade
** File description:
** Header Pacman for Library games.
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <vector>
#include <utility>
#include "IGraphicLib.hpp"
#include "IGame.hpp"

namespace arc::game {
    class Pacman : public IGame {
    public:// Map
        void init(gl::IGraphicLib *gl) override;
        void restart() override;
        std::pair<state, int> play(gl::event_t event) override;
        void display() override;
        void changeGl(gl::IGraphicLib *gl) override;

    private:
        bool loadMap();
        void waitTurn();
        void gameRun();
        void updateMap();
        void drawMap();
        void drawScore();

    private:// Perso
        void drawPerso();
        void manageEvent();
        bool checkGhost();
        void checkMove(std::pair<int, int> dir, gl::event_t event);
        void movePerso(std::pair<int, int> dir, gl::event_t event);

    private:// Ghost
        void drawGhost();
        void moveGhost(int i);
        void moveGhosts();
        void checkGDir(int i);
        bool checkPos(int x, int y);
        void chooseDir(int i, std::vector<gl::event_t> nbEvent);
        void porGDir(int i, std::vector<gl::event_t> nbEvent);
        void manageGDir(gl::event_t event, int i);
        void addPos(int i, std::pair<int, int> dir);

    private:// Ghost
        int _start;
        std::vector<gl::event_t> _sMov;
        std::vector<std::pair<int, int>> _posG;
        std::pair<int, int> _door;

    private:// Perso
        gl::event_t _event;
        gl::event_t _eventP;
        std::pair<int, int> _pos;
        std::pair<int, int> _sDir;

    private:// Map
        int _lastTurn;
        bool _drawable;
        gl::IGraphicLib *_gl;
        std::pair<int, int> _posM;
        std::vector<std::string> _map;
        state _state;
        int _score;
    };
}

#endif
