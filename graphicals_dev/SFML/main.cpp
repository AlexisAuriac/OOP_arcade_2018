//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// 
//

#include <iostream>
#include <unistd.h>
//#include "IGraphicLib.hpp"
#include "SFML.hpp"


int main()
{
    SFML game;
    textParams_t params;
    color_t color = GREEN;

    params.colorFg = GREEN;
    params.colorBg = RED;
    params.x = 350;
    params.y = 350;

    game.openWindow();
    game.clear();
    game.printText("Menu", params);
    game.drawSquare(200, 180, color);
    game.display();
    while (game.getEvent() == Unknown) {}
    game.closeWindow();
}