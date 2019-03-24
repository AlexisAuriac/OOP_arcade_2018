/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the errors of the project.
*/

#include "Error.hpp"

arc::err::Core::Core(const std::string &msg)
: _msg(msg)
{}

arc::err::Core::Core(const std::string &msg, const std::string &type)
: _msg(type + ": " + msg)
{}

const char *arc::err::Core::what() const noexcept
{
    return _msg.c_str();
}

arc::err::Argument::Argument()
: Core(arc::err::usage)
{}

arc::err::Argument::Argument(const std::string &msg)
: Core(msg, "Argument Error")
{}

arc::err::Asset::Asset(const std::string &f, const std::string &dir, const std::string &err)
: Core(f + ": " + dir + ": " + err)
{}

arc::err::Asset::Asset(const std::string &dir, const std::string &err)
: Core(dir + ": " + err)
{}

arc::err::Asset::Asset(const std::string &err)
: Core(err)
{}

arc::err::DLError::DLError(const std::string &msg)
: Core(msg, "Loading Error")
{}
