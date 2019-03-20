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

namespace arc::gl {
    template <class IGraphicLib>
    class DLLoader {
    public:
        DLLoader(const char *path)
        : _libName(path)
        {
            _lib = dlopen(path, RTLD_LAZY);

            if (_lib == nullptr)
                throw arc::err::DLError(dlerror());
        }

        ~DLLoader() {
            if (dlclose(_lib) != 0)
                std::cerr << dlerror() << std::endl;
        }

        IGraphicLib *getInstance() {
            IGraphicLib *(*entry)(void);

            entry = (IGraphicLib *(*)()) dlsym(_lib, ENTRY_POINT_NAME);
            if (entry == nullptr)
                throw arc::err::DLError(dlerror());
            return entry();
        }

    private:
        void *_lib;
        const std::string _libName;
    };
}

#endif
