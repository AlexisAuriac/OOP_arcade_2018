/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main header.
*/

#ifndef ARCADE_HPP
#define ARCADE_HPP

#include <iostream>
#include "Error.hpp"

namespace arc {
    static const int SUCCESS = 0;
    static const int FAILURE = 84;

    class Arcade {
    public:
        Arcade() = default;
        ~Arcade() = default;

        int run(int ac, char **av);

    private:
        void handle_argument_errors(int ac, char **av);
    };
}

#endif
