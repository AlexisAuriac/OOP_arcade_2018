/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for SDL1.
*/

#ifndef SLD2_HPP
#define SLD2_HPP

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unordered_map>
#include "IGraphicLib.hpp"


namespace arc::gl {
    class SDL1 : public IGraphicLib {
    public:
        const std::unordered_map<int, event_t> CONNECT_EVENTS = {
            {'A', A},
            {'B', B},
            {'C', C},
            {'D', D},
            {'E', E},
            {'F', F},
            {'G', G},
            {'H', H},
            {'I', I},
            {'J', J},
            {'K', K},
            {'L', L},
            {'M', M},
            {'N', N},
            {'O', O},
            {'P', P},
            {'Q', Q},
            {'R', R},
            {'S', S},
            {'T', T},
            {'U', U},
            {'V', V},
            {'W', W},
            {'X', X},
            {'Y', Y},
            {'Z', Z},
            {'a', A},
            {'b', B},
            {'c', C},
            {'d', D},
            {'e', E},
            {'f', F},
            {'g', G},
            {'h', H},
            {'i', I},
            {'j', J},
            {'k', K},
            {'l', L},
            {'m', M},
            {'n', N},
            {'o', O},
            {'p', P},
            {'q', Q},
            {'r', R},
            {'s', S},
            {'t', T},
            {'u', U},
            {'v', V},
            {'w', W},
            {'x', X},
            {'y', Y},
            {'z', Z},
            {'0', Num0},
            {'1', Num1},
            {'2', Num2},
            {'3', Num3},
            {'4', Num4},
            {'5', Num5},
            {'6', Num6},
            {'7', Num7},
            {'8', Num8},
            {'9', Num9},
            {SDLK_ESCAPE, Escape},
            {'[', LBracket},
            {']', RBracket},
            {';', Semicolon},
            {',', Comma},
            {'.', Period},
            {'\'', Quote},
            {'/', Slash},
            {'\\', Backslash},
            {'~', Tilde},
            {'=', Equal},
            {'-', Hyphen},
            {' ', Space},
            {SDLK_RETURN, Enter},
            {SDLK_BACKSLASH, Backspace},
            {'\t', Tab},
            {SDLK_PAGEUP, PageUp},
            {SDLK_PAGEDOWN, PageDown},
            {SDLK_END, End},
            {SDLK_HOME, Home},
            {SDLK_INSERT, Insert},
            {SDLK_DELETE, Delete},
            {'+', Add},
            {'-', Subtract},
            {'*', Multiply},
            {'/', Divide},
            {SDLK_LEFT, Left},
            {SDLK_RIGHT, Right},
            {SDLK_UP, Up},
            {SDLK_DOWN, Down},
            {SDLK_F1, F1},
            {SDLK_F2, F2},
            {SDLK_F3, F3},
            {SDLK_F4, F4},
            {SDLK_F5, F5},
            {SDLK_F6, F6},
            {SDLK_F7, F7},
            {SDLK_F8, F8},
            {SDLK_F9, F9},
            {SDLK_F10, F10},
            {SDLK_F11, F11},
            {SDLK_F12, F12},
            {SDLK_F13, F13},
            {SDLK_F14, F14},
            {SDLK_F15, F15}
        };

        const SDL_Color CONNECT_SDL_COLORS[NB_COLORS] = {
            [BLACK] = SDL_Color {0, 0, 0, 0},
            [BLUE] = SDL_Color {0, 0, 0xff, 0},
            [GREEN] = SDL_Color {0, 0xff, 0, 0},
            [CYAN] = SDL_Color {0x00, 0xff, 0xff, 0},
            [RED] = SDL_Color {0xff, 0, 0, 0},
            [MAGENTA] = SDL_Color {0xff, 0, 0xff, 0},
            [WHITE] = SDL_Color {0xff, 0xff, 0xff, 0},
            [GRAY] = SDL_Color {0x7f, 0x7f, 0x7f, 0},
            [YELLOW] = SDL_Color {0xff, 0xff, 0, 0}
        };

        const Uint32 CONNECT_UINT_COLORS[NB_COLORS] = {
            [BLACK] = 0x00000000,
            [BLUE] = 0x000000ff,
            [GREEN] = 0x0000ff00,
            [CYAN] = 0x0000ffff,
            [RED] = 0x00ff0000,
            [MAGENTA] = 0x00ff00ff,
            [WHITE] = 0x00ffffff,
            [GRAY] = 0x007f7f7f,
            [YELLOW] = 0x00ffff00
        };

        static const int WINDOW_WIDTH = 1080;
        static const int WINDOW_HEIGHT = 720;
        static const int BLOCK_SIZE = 20;

        const char *FONT_PATH = "./assets/arial.ttf";

    public:
        SDL1();
        ~SDL1();
        void openWindow() override;
        event_t getEvent() override;
        void clear() override;
        void display() override;
        int getCols() override;
        int getLines() override;
        void printText(
            const std::string &str,
            const textParams_t &params) override;
        void drawSquare(int x, int y, color_t color) override;
        void closeWindow() override;

    private:
        SDL_Surface *_screen = nullptr;
        SDL_Surface *_square;
        TTF_Font *_font;
    };
}

#endif

