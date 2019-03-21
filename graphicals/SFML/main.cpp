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
     game.getEvent();
     game.clear();
    game.printText( "ok", 5, 5);
     game.display();
    //game.getBlock(3, 4);
    sleep(5);
    game.closeWindow();
}