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

    game.openWindow();
    //game.clear();
    //game.printText("Menu", params);
    //game.drawSquare(200, 180, color);
    //game.display();
    while (game.getEvent() == Unknown) {}
    game.closeWindow();
}
