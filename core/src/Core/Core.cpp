/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the main methods of the Core class.
*/

#include <iostream>
#include "Core.hpp"
#include "Error.hpp"
#include "MainMenu.hpp"

arc::Core::~Core()
{
    delete _gl;
}

void arc::Core::handleArgumentErrors(
    int ac,
    __attribute__((unused)) char **av)
{
    if (ac != 2)
        throw arc::err::Argument();
}

void arc::Core::handleEvent(gl::event_t event)
{
    switch (event) {
    case gl::Escape:
        _state = OVER;
        break;
    }
}

void arc::Core::mainLoop()
{
    arc::gl::event_t event;

    _gl->openWindow();
    _menu.init(_gl, _gls, _games);
    while (_state != OVER) {
        event = _gl->getEvent();
        handleEvent(event);
        if (_state == IN_MENU) {
            std::pair<arc::MainMenu::action, const std::string &> res = _menu.handleEvent(event);

            switch (res.first) {
            case arc::MainMenu::SELECT_GL:
                _glLoader.loadLib(res.second);
                break;
            case arc::MainMenu::SELECT_GAME:
                _state = IN_GAME;
                // _gameLoader.loadLib(res.second);
                break;
            }
            _menu.display();
        } else if (_state == IN_GAME) {
            _gl->clear();
            _gl->printText("lol", gl::textParams());
            _gl->display();

            if (event == gl::Space)
                _state = IN_MENU;
        }
        // else if (_state == IN_GAME) {
        //     std::pair<game::state, int> res = _game.play(event);

        //     if (res.first == game::OVER) {
        //         _state = IN_MENU;
        //         _gameLoader.closeLib();
        //         saveScore(res.second);
        //     }
        //     _game.display();
        // }
    }
    _gl->closeWindow();
}

int arc::Core::run(int ac, char **av)
{
    try {
        handleArgumentErrors(ac, av);
        init(av[1]);
        mainLoop();
    } catch (const arc::err::Core &e) {
        std::cerr << e.what() << std::endl;
        return arc::FAILURE;
    }
    return arc::SUCCESS;
}
