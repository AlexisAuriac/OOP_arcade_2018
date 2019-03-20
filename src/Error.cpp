/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the errors of the project.
*/

#include "Error.hpp"

arc::err::Arcade::Arcade(const std::string &msg)
: _msg(msg)
{}

arc::err::Arcade::Arcade(const std::string &msg, const std::string &type)
: _msg(type + ": " + msg)
{}

const char *arc::err::Arcade::what() const noexcept
{
    return _msg.c_str();
}

arc::err::Argument::Argument()
: Arcade(arc::err::usage)
{}

arc::err::Argument::Argument(const std::string &msg)
: Arcade(msg, "Argument Error")
{}
