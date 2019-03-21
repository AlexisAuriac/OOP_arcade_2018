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

arc::err::Asset::Asset(const std::string &f, const std::string &dir, const std::string &err)
: Arcade(f + ": " + dir + ": " + err)
{}
arc::err::Asset::Asset(const std::string &dir, const std::string &err)
: Arcade(dir + ": " + err)
{}
arc::err::Asset::Asset(const std::string &err)
: Arcade(err)
{}

arc::err::DLError::DLError(const std::string &msg)
: Arcade(msg, "Loading Error")
{}
