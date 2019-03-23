/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the templated DLLoader class to load graphic libraries.
*/

#ifndef DLLOADER_LIBS_HPP
#define DLLOADER_LIBS_HPP

#include <iostream>
#include <string>
#include <dlfcn.h>
#include "IGraphicLib.hpp"
#include "Error.hpp"

namespace arc {
    template <class T> class DLLoader;

    template <>
    class DLLoader<gl::IGraphicLib> {
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

            if (dlopen(path.c_str(), RTLD_LAZY | RTLD_NOLOAD))
                throw arc::err::DLError(path + ": already open");
            newLib = dlopen(path.c_str(), RTLD_LAZY);
            if (newLib == nullptr)
                throw arc::err::DLError(dlerror());
            if (_lib != nullptr)
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

        gl::IGraphicLib *getInstance() {
            gl::IGraphicLib *(*entry)(void);

            entry = (gl::IGraphicLib *(*)()) dlsym(_lib, gl::ENTRY_POINT_NAME);
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
