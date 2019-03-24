/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include <string>
#include "Core.hpp"
#include "IGraphicLib.hpp"
#include "MainMenu.hpp"

void arc::MainMenu::init(
    gl::IGraphicLib *gl,
    std::vector<std::string> &gls,
    std::vector<std::string> &games)
{
    _gl = gl;
    _gls = gls;
    _games = games;
}

void arc::MainMenu::changeLib(gl::IGraphicLib *gl)
{
    _gl = gl;
}

bool arc::MainMenu::HandleMove(gl::event_t event)
{
    std::vector<std::string> &currList = (_pos.first == 0) ? _gls : _games;

    if (event == arc::gl::Down) {
        ++_pos.second;
        if (_pos.second > currList.size() - 1)
            _pos.second = 0;
        return true;
    } else if (event == arc::gl::Up) {
        if (_pos.second == 0)
            _pos.second = currList.size() - 1;
        else
            --_pos.second;
        return true;
    } else if (event == arc::gl::Left || event == arc::gl::Right) {
        _pos.first = (_pos.first == 0) ? 1 : 0;
        _pos.second = 0;
        return true;
    }
    return false;
}

std::pair<arc::MainMenu::action, const std::string>
arc::MainMenu::handleEvent(gl::event_t event)
{
    if (HandleMove(event))
        return std::make_pair(MOVE, "");
    if (event == arc::gl::Enter) {
        if (_pos.first == 0)
            return std::make_pair(SELECT_GL, _gls[_pos.second]);
        else if (_pos.first == 1)
            return std::make_pair(SELECT_GAME, _games[_pos.second]);
    }
    return std::make_pair(NOTHING, "");
}

void arc::MainMenu::displayList(
    unsigned int nbList,
    const std::string &listName,
    std::vector<std::string> entries,
    int col)
{
    int lines = _gl->getLines();
    gl::textParams_t params;
    unsigned int i = 0;

    params.x = col;
    params.y = lines / 2 + (entries.size() / 2) - entries.size() - 1;
    params.bold = true;
    params.centered = true;
    _gl->printText(listName, params);
    params.bold = false;
    for (const std::string &s : entries) {
        ++params.y;
        params.colorFg = arc::gl::WHITE;
        if (_pos.first == nbList && i == _pos.second)
            params.colorBg = arc::gl::BLUE;
        else
            params.colorBg = arc::gl::BLACK;
        _gl->printText(s, params);
        ++i;
    }
}

void arc::MainMenu::display()
{
    _gl->clear();
    displayList(0, "LIBS", _gls, _gl->getCols() / 4);
    displayList(1, "GAMES", _games, _gl->getCols() / 4 * 3);
    _gl->display();
}
