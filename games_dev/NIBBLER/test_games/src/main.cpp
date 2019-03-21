#include <iostream>
#include "DLLoaderLib.hpp"
#include "IGraphicLib.hpp"
#include "Nibbler.hpp"

int main(int ac, char **av)
{
    arc::DLLoader<arc::gl::IGraphicLib> loader(av[1]);
    arc::gl::IGraphicLib *gl = loader.getInstance();

    gl->openWindow();
    Nibbler t(gl);
    t.gameRun(gl);
    gl->closeWindow();
    delete gl;
    return 0;
}