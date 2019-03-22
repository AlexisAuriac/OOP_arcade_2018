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
    game.openWindow();
     game.clear();
     //game.printText( "Menu", 50, 15);
     game.display();
     //game.drawSquare(3, 4);
    while (game.getEvent() == Unknown) {}
    game.closeWindow();
}