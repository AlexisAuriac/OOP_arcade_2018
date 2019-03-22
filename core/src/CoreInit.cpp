/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Intializes the Core object.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <dirent.h>
#include <unistd.h>
#include "Core.hpp"
#include "Error.hpp"

void arc::Core::ReadLibDir(
    const char *dirName,
    std::list<std::string> &fList)
{
    DIR *dir = opendir(dirName);
    struct dirent *file = nullptr;

    fList.clear();
    if (dir == nullptr)
        throw arc::err::Asset("opendir", dirName, strerror(errno));
    while (true) {
        file = readdir(dir);
        if (!file)
            break;
        else if (file->d_name[0] == '.')
            continue;
        fList.push_back(file->d_name);
    }
    fList.sort();
    closedir(dir);
}

void arc::Core::getAssets()
{
    ReadLibDir(arc::GAMES_DIR, _games);
    ReadLibDir(arc::GLS_DIR, _gls);
}

std::string arc::Core::trimPath(const std::string &libName) noexcept
{
    try {
        return libName.substr(libName.rfind('/') + 1);
    } catch (const std::out_of_range &e) {
        return libName;
    }
}

void arc::Core::init(const std::string &libName)
{
    _glLoader.loadLib(libName.c_str());
    _gl = _glLoader.getInstance();
    getAssets();
    _currGl = trimPath(libName);
}
