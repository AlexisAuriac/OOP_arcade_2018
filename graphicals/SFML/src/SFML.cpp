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

void SFML::getBlock(int a, int b)
{
    sf::CircleShape square(a, b);
    sf::Texture texture;
    //texture.create(2, 2);
    sf::Uint8 *pixels = new sf::Uint8[640, 480];

    for (int x = 0; x < 640; ++x)
        for (int y = 0; y < 480; ++y)
        {
            pixels[(x + y * 2) * 4 + 0] = 0;   
            pixels[(x + y * 2) * 4 + 1] = 255; 
            pixels[(x + y * 2) * 4 + 2] = 0;   
            pixels[(x + y * 2) * 4 + 3] = 128; 
        }
        texture.update(pixels);
    _window.draw(square);
}

void SFML::closeWindow()
{
    _window.close();
}

