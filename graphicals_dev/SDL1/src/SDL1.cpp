/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file of the SDL1 graphical library.
*/

#include <iostream>
#include <SDL/SDL.h>
#include "IGraphicLib.hpp"
#include "SDL1.hpp"

#include <unistd.h>

arc::gl::SDL1::SDL1()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    _square = SDL_CreateRGBSurface(
        SDL_HWSURFACE, BLOCK_SIZE, BLOCK_SIZE, 32, 0, 0, 0, 0);
    _font = TTF_OpenFont("./assets/arial.ttf", BLOCK_SIZE);
    TTF_SetFontStyle(_font, TTF_STYLE_NORMAL);
}

arc::gl::SDL1::~SDL1()
{
    SDL_FreeSurface(_square);
    TTF_CloseFont(_font);

    TTF_Quit();
    SDL_Quit();
}

void arc::gl::SDL1::openWindow()
{
    _screen = SDL_SetVideoMode(
        WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Arcade", nullptr);
}

void arc::gl::SDL1::closeWindow()
{
    SDL_FreeSurface(_screen);
}

arc::gl::event_t arc::gl::SDL1::getEvent()
{
    SDL_Event event = {0};

    SDL_PollEvent(&event);
    if (event.type != SDL_KEYDOWN) {
        return Unknown;
    } else {
        try {
            return CONNECT_EVENTS.at(event.key.keysym.sym);
        } catch (const std::out_of_range &e) {
            return Unknown;
        }
    }
}

int arc::gl::SDL1::getCols()
{
    return WINDOW_WIDTH / BLOCK_SIZE;
}

int arc::gl::SDL1::getLines()
{
    return WINDOW_HEIGHT / BLOCK_SIZE;
}

void arc::gl::SDL1::drawSquare(int x, int y, arc::gl::color_t color)
 {
    SDL_Color ncColor = CONNECT_COLORS[color];
    SDL_Rect position;
    union {SDL_Color color; Uint32 uint;} conv = {ncColor};

    SDL_FillRect(_square, nullptr, conv.uint);
    position.x = x * BLOCK_SIZE;
    position.y = y * BLOCK_SIZE;
    SDL_BlitSurface(_square, nullptr, _screen, &position);
 }

void arc::gl::SDL1::printText(
    const std::string &str,
    const textParams_t &params)
{
    SDL_Color fill = CONNECT_COLORS[params.colorFg];
    SDL_Color back = CONNECT_COLORS[params.colorBg];
    SDL_Rect position;
    SDL_Surface *text = TTF_RenderText_Shaded(
        _font,
        str.c_str(),
        fill,
        back);

    position.x = params.x * BLOCK_SIZE;
    position.y = params.y * BLOCK_SIZE;
    SDL_BlitSurface(text, nullptr, _screen, &position);
    SDL_FreeSurface(text);
}

void arc::gl::SDL1::clear()
{
    SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0, 0, 0));
}

void arc::gl::SDL1::display()
{
    SDL_Flip(_screen);
}

extern "C" arc::gl::IGraphicLib *entryPoint()
{
    return new arc::gl::SDL1();
}
