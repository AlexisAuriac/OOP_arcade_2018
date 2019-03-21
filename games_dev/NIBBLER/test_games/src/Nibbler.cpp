/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Functions a Nibbler games.
*/

#include <ncurses.h>
#include <iostream>
#include "Nibbler.hpp"

Nibbler::Nibbler()
// : _row(LINES), _col(COLS)
{
    std::cout << "Construction" << std::endl;
    _tail.push_back(std::make_pair(0, 0));
    _tail.push_back(std::make_pair(1, 0));
    _tail.push_back(std::make_pair(2, 0));
}

void Nibbler::print_snake()
{
    for (int i = 0; i < (int)_tail.size(); i++)
        std::cout << "[" << _tail[i].first << "," << _tail[i].second << "]" << std::endl;
}

Nibbler::~Nibbler()
{
    std::cout << "Destruction" << std::endl;
}