//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// 
//

#include <iostream>
#include <unistd.h>
//#include "IGraphicLib.hpp"
#include "SDL2.hpp"


int main()
{
    SDL game;
    textParams_t params;
    color_t color = GRAY;

    params.colorFg = GREEN;
    params.colorBg = RED;
    params.x = 35;
    params.y = 65;

    game.openWindow();
    //game.clear();
    game.printText("MENUPPPPPP", params);
    game.drawSquare(200, 180, color);
    //game.display();
    while (game.getEvent() == Unknown) {}
    game.closeWindow();
}
