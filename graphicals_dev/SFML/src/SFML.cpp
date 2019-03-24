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

arc::gl::SFML::SFML()
{
    _font.loadFromFile(FONT_PATH); // TODO: test and throw
    _text.setCharacterSize(BLOCK_SIZE);
    _text.setFont(_font);
}

void arc::gl::SFML::openWindow()
{
    _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arcade");
    _window.setFramerateLimit(FRAME_RATE);
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
    return WINDOW_WIDTH / BLOCK_SIZE;
}

int arc::gl::SFML::getLines()
{
    return WINDOW_HEIGHT / BLOCK_SIZE;

}
 void arc::gl::SFML::drawSquare(int x, int y, color_t color)
 {
    _rectShape.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));

    _rectShape.setFillColor(CONNECT_COLORS[color]);
    _rectShape.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
     _window.draw(_rectShape);
 }

void arc::gl::SFML::printText(
    const std::string &str,
    const textParams_t &params)
{
    sf::Color fill = CONNECT_COLORS[params.colorFg];
    sf::Color outline = CONNECT_COLORS[params.colorBg];
    sf::FloatRect textRect;
    sf::Vector2f pos(params.x * BLOCK_SIZE, params.y * BLOCK_SIZE);

    if (params.bold)
        _text.setStyle(sf::Text::Bold);
    else
        _text.setStyle(sf::Text::Regular);
    _text.setString(str);
    textRect = _text.getLocalBounds();
    if (params.centered)
        pos.x -= textRect.width / 2;
    _text.setFillColor(fill);
    _text.setPosition(pos);

    _rectShape.setSize(sf::Vector2f(textRect.width, textRect.height));
    _rectShape.setFillColor(outline);
    _rectShape.setPosition(pos);
     _window.draw(_rectShape);

    _window.draw(_text);
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

extern "C" arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::SFML();
}
