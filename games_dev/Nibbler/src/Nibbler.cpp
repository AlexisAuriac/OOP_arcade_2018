/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Functions a Nibbler games.
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Nibbler.hpp"

void arc::game::Nibbler::init(gl::IGraphicLib *gl)
{
    useconds_t arr[] = {0, 0, 0, 0, 0,17000, 13000, 10000, 9500,
        9000, 8300, 7600, 6900, 6200, 5600, 5000, 4600, 4200,
        3800, 3650, 3500, 3400, 3325, 3250, 3150, 3100, 3050};
    int arr1[] = {0, 0, 0, 0, 0, 0, 100, 150, 225, 300, 400, 525, 675,
        550, 1050, 1275, 1525, 1700, 2000, 2325, 2675, 3050,
        3450, 3875, 4325, 4800, 5300};
    int n = sizeof(arr) / sizeof(arr[0]);

    _gl = gl;
    _row = gl->getLines();
    _col = gl->getCols();
    for (int i = 0 ; i < n ; ++i)
        _tabScore.push_back(std::make_pair(arr[i], arr1[i]));
    _tail.push_back(std::make_pair((_col / 2), (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 1, (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 2, (_row / 2)));
    _tail.push_back(std::make_pair((_col / 2) - 3, (_row / 2)));
    _run = 1;
    _movx = 1;
    _movy = 0;
    _index = _tail.size();
    posFruit(1);
}

void arc::game::Nibbler::restart()
{
    _tail.clear();
    _tabScore.clear();
    init(_gl);
}

extern "C" arc::game::IGame *entryPoint()
{
    return new arc::game::Nibbler();
}
