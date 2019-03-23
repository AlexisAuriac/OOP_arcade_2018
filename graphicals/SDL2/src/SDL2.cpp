/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file of the SDL2 graphical library.
*/

#include <iostream>
#include "IGraphicLib.hpp"
#include "SDL2.hpp"

void SDL::openWindow()
{
    std::cout<< "ok" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(400, 300, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Arcade", NULL);
}

event_key SDL::getEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.key.keysym.sym != SDL_KEYDOWN) {
        return Unknown;
    } else {
        try {
            return event_tab.at(event.key.keysym.sym);
        } catch (const std::out_of_range &e) {
            return Unknown;
        }
    }
}

int SDL::getCols()
{
    return size_window_width / size_block;
}

int SDL::getLines()
{
    return size_window_height /size_block;
    
}
 //void SDL::drawSquare(int x, int y, color_t color)
 //{
     /*
    sf::RectangleShape square(sf::Vector2f(60, 60));
    sf::Color ncColor = CONNECT_COLORS[color];
    square.setFillColor(ncColor);
    square.setPosition(x, y);

     _window.draw(square);
     */
 //}

void SDL::printText(
    const std::string &str, 
    const textParams_t &params)
{
    /*
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
    */
}

void SDL::clear()
{
    //_window.clear();
}

void SDL::display()
{
    //_window.display();
}

void SDL::closeWindow()
{
    SDL_Quit();
}


//extern "C"
//arc::gl::IGraphicLib *entryPoint()
//{
  //  return new arc::gl::SDL2();
//}
