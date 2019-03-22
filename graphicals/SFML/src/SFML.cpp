/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file of the SDL2 graphical library.
*/

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "IGraphicLib.hpp"
#include "SFML.hpp"

void SFML::openWindow()
{
    _window.create(sf::VideoMode(640, 480), "Arcade");
}

event_key SFML::getEvent()
{
    sf::Event event;

    _window.pollEvent(event);

    if(event.type != sf::Event::KeyPressed) {
        return Unknown;
    } else {
        try {
            return event_tab.at(event.key.code);
        } catch (const std::out_of_range &e) {
            return Unknown;
        }
    }
}

void arc::gl::Ncurses::printText(
    const std::string &str,
    const textParams_t &params)
{
    int len = str.length();
    int correctedCol;
    int fg = CONNECT_COLORS[params.colorFg];
    int bg = CONNECT_COLORS[params.colorBg];

    if (params.x + len > COLS)
        correctedCol = COLS - len;
    else {
        correctedCol = params.x - len / 2;
        if (correctedCol < 0)
            correctedCol = 0;
    }
    attron(COLOR_PAIR(fg * 16 + bg));
    if (params.bold)
        attron(A_BOLD);
    else
        attroff(A_BOLD);
    mvprintw(params.y, correctedCol, str.c_str());
}



void SFML::printText(const std::string &str, int a, int b)
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return;
    sf::Text text;

    text.setFont(font);
    text.setString(str);
    text.setPosition(a, b);
    _window.draw(text);
}

void SFML::clear()
{
    _window.clear();
}

void SFML::display()
{
    _window.display();
}

// void SFML::openDraw()
// {
//     _window.draw()
// }


void arc::gl::Ncurses::drawSquare(int x, int y, arc::gl::color_t color)
{
    int ncColor = CONNECT_COLORS[color];

    attron(COLOR_PAIR(ncColor * 16 + ncColor));
    mvprintw(y, x, " ");
}

void SFML::closeWindow()
{
    _window.close();
}

