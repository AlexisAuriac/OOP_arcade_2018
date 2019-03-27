/*
** EPITECH, 2018
** Pacman.hpp
** File description:
** Header Pacman for Library games.
*/

#include "Pacman.hpp"

class Ghost : public Pacman 
{
    public:
        std::pair <int, int> _Pos;
};