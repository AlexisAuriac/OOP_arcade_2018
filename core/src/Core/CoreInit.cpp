/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Intializes the Core object.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <dirent.h>
#include "Core.hpp"
#include "Error.hpp"

void arc::Core::readLibDir(
    const char *dirName,
    std::vector<std::string> &fList)
{
    DIR *dir = opendir(dirName);
    struct dirent *file = nullptr;
    std::string path(dirName);

    fList.clear();
    if (dir == nullptr)
        throw arc::err::Asset("opendir", dirName, strerror(errno));
    while (true) {
        file = readdir(dir);
        if (!file)
            break;
        else if (file->d_name[0] == '.')
            continue;
        std::string path = std::string(dirName);
        fList.push_back(path + file->d_name);
    }
    sort(fList.begin(), fList.end());
    closedir(dir);
}

void arc::Core::getAssets()
{
    readLibDir(arc::GAMES_DIR, _games);
    readLibDir(arc::GLS_DIR, _gls);
}

void arc::Core::init(const std::string &libName)
{
    _glLoader.loadLib(libName.c_str());
    _gl = _glLoader.getInstance();
    getAssets();
}
