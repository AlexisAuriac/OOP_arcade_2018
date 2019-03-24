#include <iostream>
#include "DLLoaderLib.hpp"
#include "IGraphicLib.hpp"
#include "Pacman.hpp"

int main(int ac, char **av)
{
    arc::DLLoader<arc::gl::IGraphicLib> loader(av[1]);
    arc::gl::IGraphicLib *gl = loader.getInstance();
    Pacman t;

    t.init(gl);
    gl->openWindow();
    t.gameRun(gl);
    gl->closeWindow();
    delete gl;
    return 0;
}