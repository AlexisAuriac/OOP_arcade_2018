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

arc::Core::Core()
{
    srand(time(NULL));
}

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

bool arc::Core::handleEvent(gl::event_t event)
{
    switch (event) {
    case gl::Escape:
        _state = OVER;
        return true;
    case gl::Num1:
        _state = IN_MENU;
        _gameLoader.closeLib();
        return true;
    case gl::Num2:
        if (_state == IN_GAME)
            _game->restart();
        return true;
    case gl::Num3:
        if (_gls.size() == 0)
            return true;
        else if (_currGl == 0 || _currGl > _gls.size() - 1)
            _currGl = _gls.size() - 1;
        else
            --_currGl;
        _glLoader.switchLib(_gls[_currGl], _gl);
        _gl->openWindow();
        _menu.changeLib(_gl);
        if (_state == IN_GAME)
            _game->changeGl(_gl);
        return true;
    case gl::Num4:
        if (_gls.size() == 0)
            return true;
        else if (_currGl >= _gls.size() - 1)
            _currGl = 0;
        else
            ++_currGl;
        _glLoader.switchLib(_gls[_currGl], _gl);
        _gl->openWindow();
        _menu.changeLib(_gl);
        if (_state == IN_GAME)
            _game->changeGl(_gl);
        return true;
    default:
        return false;
    }
}

void arc::Core::alert(const std::string &str) const
{
    _gl->printText(str, gl::textParams());
    _gl->display();
    while (_gl->getEvent() == gl::Unknown) {}
}

void arc::Core::playMenu(gl::event_t event)
{
    std::pair<arc::MainMenu::action, const std::string> res = _menu.handleEvent(event);

    if (res.first == arc::MainMenu::SELECT_GL) {
        try {
            _glLoader.switchLib(res.second, _gl);
        } catch (const arc::err::DLError &e) {
            alert(e.what());
            return;
        }
        _gl->openWindow();
        _menu.changeLib(_gl);
        _currGl = _menu.getPos().second;
    } else if (res.first == arc::MainMenu::SELECT_GAME) {
        _state = IN_GAME;
        _gameLoader.loadLib(res.second);
        _game = _gameLoader.getInstance();
        _game->init(_gl);
    } else
        _menu.display();
}

void arc::Core::playGame(gl::event_t event)
{
    std::pair<game::state, int> res = _game->play(event);

    if (res.first == game::OVER) {
        _state = IN_MENU;
        delete _game;
        _gameLoader.closeLib();
        // saveScore(res.second);
    } else
        _game->display();
}

void arc::Core::mainLoop()
{
    arc::gl::event_t event;

    _gl->openWindow();
    _menu.init(_gl, _gls, _games);
    while (_state != OVER) {
        event = _gl->getEvent();
        if (handleEvent(event))
            continue;
        if (_state == IN_MENU)
            playMenu(event);
        else if (_state == IN_GAME)
            playGame(event);
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
