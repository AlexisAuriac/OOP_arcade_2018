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
    _window.create(sf::VideoMode(size_window_width, size_window_height), "Arcade");
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

int getCols()
{
    return size_window_width / size_block;
}

int getLine()
{
    return size_window_height /size_block;
    
}
 void SFML::drawSquare(int x, int y, color_t color)
 {
    sf::RectangleShape square(sf::Vector2f(60, 60));
    sf::Color ncColor = CONNECT_COLORS[color];
    square.setFillColor(ncColor);
    square.setPosition(x, y);

     _window.draw(square);
 }

void SFML::printText(
    const std::string &str, 
    const textParams_t &params)
{
    int correctedCol;
    sf::Color fill = CONNECT_COLORS[params.colorFg];
    sf::Color outline = CONNECT_COLORS[params.colorBg];
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return;
    sf::Text text;

    if (params.bold) {
        text.setStyle(sf::Text::Bold);
    }
    text.setFont(font);
    text.setString(str);
    text.setFillColor(fill);
    text.setOutlineColor(outline);
    text.setPosition(params.x, params.y);
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

void SFML::closeWindow()
{
    _window.close();
}

