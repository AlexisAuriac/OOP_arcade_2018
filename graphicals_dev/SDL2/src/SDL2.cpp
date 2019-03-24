/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file of the SDL2 graphical library.
*/

#include <iostream>
#include "IGraphicLib.hpp"
#include <SDL/SDL.h>
#include "SDL2.hpp"

void SDL::openWindow()
{
    std::cout<< "ok" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(size_window_width, size_window_height, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Arcade", NULL);
}

event_key SDL::getEvent()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type != SDL_KEYDOWN) {
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

Uint32 sdl_color_to_uint32(SDL_Color color)
{
    union {
        SDL_Color color;
        Uint32 uint;
    } conv = {color};

    return conv.uint;
}

void SDL::drawSquare(int x, int y, color_t color)
 {
    SDL_Surface *square = NULL;
    square = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
    SDL_Color ncColor = CONNECT_COLORS[color];
    SDL_FillRect(square, NULL, sdl_color_to_uint32(ncColor));
    SDL_Rect position;
    position.x = (640 / 2) - (220 / 2);
    position.y = (480 / 2) - (180 / 2);
    SDL_BlitSurface(square, NULL, ecran, &position);
    SDL_Flip(ecran);
    SDL_FreeSurface(square);
 }

void SDL::printText(
    const std::string &str, 
    const textParams_t &params)
{
    TTF_Init();
    SDL_Color fill = CONNECT_COLORS[params.colorFg];
    SDL_Color outline = CONNECT_COLORS[params.colorBg];
    SDL_Rect position;
    TTF_Font *police = TTF_OpenFont("arial.ttf", 22);
    SDL_Surface *texte = TTF_RenderText_Blended(police, str.c_str(), fill);
    position.x = params.x;
    position.y = params.y;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_Flip(ecran);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
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
