/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a Nibbler games.
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <iostream>
#include <vector>
#include <utility>

class Nibbler
{
    private:
        // int _row;
        // int _col;
        std::vector< std::pair <int, int> > _tail;
    public:
        Nibbler();
        ~Nibbler();
        void print_snake();
};

#endif