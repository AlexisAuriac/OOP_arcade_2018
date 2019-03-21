/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the errors of the project.
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

namespace arc::err {
    static const std::string usage =
    "USAGE\n"
    "\t./arcade library\n"
    "\n"
    "DESCRIPTION\n"
    "\tlibrary\t\tdynamic linked graphic library";

    class Arcade : public std::exception {
    public:
        Arcade(const std::string &msg);
        Arcade(const std::string &msg, const std::string &type);

        const char *what() const noexcept override;

    private:
        const std::string _msg;
    };

    class Argument : public Arcade {
    public:
        Argument();
        Argument(const std::string &msg);
    };

    class Asset : public Arcade {
    public:
        Asset(const std::string &f, const std::string &dir, const std::string &err);
        Asset(const std::string &dir, const std::string &err);
        Asset(const std::string &err);
    };

    class DLError : public Arcade {
    public:
        DLError(const std::string &msg);
    };
}

#endif
