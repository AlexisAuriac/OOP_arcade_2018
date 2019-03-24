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

void arc::gl::SFML::openWindow()
{
    _window.create(sf::VideoMode(windowWidth, windowHeight), "Arcade");
}

event_key arc::gl::SFML::getEvent()
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

int arc::gl::SFML::getCols()
{
    return windowWidth /  blockSize;
}

int arc::gl::SFML::getLines()
{
    return windowHeight / blockSize;

}
 void arc::gl::SFML::drawSquare(int x, int y, color_t color)
 {
    sf::RectangleShape square(sf::Vector2f(60, 60));
    sf::Color ncColor = CONNECT_COLORS[color];
    square.setFillColor(ncColor);
    square.setPosition(x, y);

     _window.draw(square);
 }

void arc::gl::SFML::printText(
    const std::string &str,
    const textParams_t &params)
{
    sf::Color fill = CONNECT_COLORS[params.colorFg];
    sf::Color outline = CONNECT_COLORS[params.colorBg];
    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile(("arial.ttf"))) // TODO: test and throw
        return;
    if (params.bold)
        text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setString(str);
    text.setFillColor(fill);
    text.setOutlineColor(outline);
    text.setPosition(params.x, params.y);
    _window.draw(text);
}

void arc::gl::SFML::clear()
{
    _window.clear();
}

void arc::gl::SFML::display()
{
    _window.display();
}

void arc::gl::SFML::closeWindow()
{
    _window.close();
}
