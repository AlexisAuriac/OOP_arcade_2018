/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the templated DLLoader class to load games libraries.
*/

#ifndef DLLOADER_GAMES_HPP
#define DLLOADER_GAMES_HPP

#include <iostream>
#include <string>
#include <dlfcn.h>
#include "IGame.hpp"
#include "DLLoaderLib.hpp"
#include "Error.hpp"

namespace arc {
    template <class T> class DLLoader;

    template <>
    class DLLoader<game::IGame> {
    public:
        DLLoader() = default;

        DLLoader(const char *path) {
            loadLib(path);
        }

        ~DLLoader() {
            closeLib();
        }

        void loadLib(const std::string &path) {
            void *newLib;

            newLib = dlopen(path.c_str(), RTLD_LAZY);
            if (newLib == nullptr)
                throw arc::err::DLError(dlerror());
            if (_lib != nullptr)
                closeLib();
            _lib = newLib;
        }

        void switchLib(const std::string &path, game::IGame *&inst) {
            void *newLib;
            game::IGame *newInst;

            newLib = dlopen(path.c_str(), RTLD_LAZY);
            if (newLib == nullptr)
                throw arc::err::DLError(dlerror());
            newInst = getInstance(newLib);
            delete inst;
            inst = newInst;
            closeLib();
            _lib = newLib;
        }

        void closeLib() {
            if (_lib == nullptr)
                return;
            if (dlclose(_lib) != 0)
                std::cerr << dlerror() << std::endl;
            _lib = nullptr;
        }

        game::IGame *getInstance() {
            return getInstance(_lib);
        }

        game::IGame *getInstance(void *handle) {
            game::IGame *(*entry)(void);

            entry = (game::IGame *(*)()) dlsym(handle, game::ENTRY_POINT_NAME);
            if (entry == nullptr)
                throw arc::err::DLError(dlerror());
            try {
                return entry();
            } catch (const std::bad_alloc &e) {
                throw arc::err::DLError("Library creation failed");
            }
        }

    private:
        void *_lib = nullptr;
    };
}

#endif
