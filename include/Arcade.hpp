/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main header.
*/

#ifndef ARCADE_HPP
#define ARCADE_HPP

#include <iostream>
#include <exception>
#include <elf.h>

namespace arc {
    static const int SUCCESS = 0;
    static const int FAILURE = 84;

    class Arcade {
    public:
        Arcade()
        ~Arcade();

        int run(int ac, char **av);
    };

    class Error : public std::exception {
    public:
        Error(std::string const& msg = "")
        : _msg(msg)
        {}
        
        const char *what() const no_except override
        {
            return _msg.c_str();
        }

    private:
        const std::string _msg;
    };
}
#endif
