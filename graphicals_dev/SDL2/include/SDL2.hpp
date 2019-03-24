/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for SDL2.
*/

#ifndef SLD2_HPP
#define SLD2_HPP

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unordered_map>
//#include "IGraphicLib.hpp"

enum {
    Unknown = -1,
    A = 0,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Num0,
    Num1,
    Num2,
    Num3,
    Num4,
    Num5,
    Num6,
    Num7,
    Num8,
    Num9,
    Escape,
    LBracket,
    RBracket,
    Semicolon,
    Comma,
    Period,
    Quote,
    Slash,
    Backslash,
    Tilde,
    Equal,
    Hyphen,
    Space,
    Enter,
    Backspace,
    Tab,
    PageUp,
    PageDown,
    End,
    Home,
    Insert,
    Delete,
    Add,
    Subtract,
    Multiply,
    Divide,
    Left,
    Right,
    Up,
    Down,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    KeyCount,
};

typedef int event_key;

static const std::unordered_map<int, event_key> event_tab = {
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
            {'\n', Enter},
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

enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    WHITE,
    GRAY,
    YELLOW,
    NB_COLORS
};

const SDL_Color CONNECT_COLORS[NB_COLORS] = {

    [BLACK] = SDL_Color {0, 0, 0},
    [BLUE] = SDL_Color {0x14, 0xAD, 0xDB, 0x00},
    [GREEN] = SDL_Color {0x2F, 0xB0, 0x04, 0x00},
    [CYAN] = SDL_Color {52, 0, 13, 0},
    [RED] = SDL_Color {0xFF, 0x00, 0x00, 0x00},
    [MAGENTA] = SDL_Color {0, 100, 0, 0},
    [WHITE] = SDL_Color {0xFF, 0xFF, 0xFF, 0x00},
    [GRAY] = SDL_Color {127, 127, 127},
    [YELLOW] = SDL_Color {0xFF, 0xFF, 0x00, 0x00},

};


typedef int color_t;

typedef struct textParams {
    short x;
    short y;
    color_t colorFg : 4;
    color_t colorBg : 4;
    bool bold : 1;

    textParams(
        int x = 0,
        int y = 0,
        int fg = WHITE,
        int bg = BLACK,
        bool bold = false)
    : x(x), y(y), colorFg(fg), colorBg(bg), bold(bold)
    {}
} textParams_t;


// namespace arc::gl {
    // class SFML : public IGraphicLib {
    class SDL {
    public:
        void openWindow();
        event_key getEvent();
        void clear();
        void display();
        int getCols();
        int getLines();
        void printText(
            const std::string &str,
            const textParams_t &params);
        void drawSquare(int x, int y, color_t color);
        void closeWindow();

    private:
        SDL_Surface *ecran = nullptr;
        const int size_window_width = 700;
        const int size_window_height = 550;
        const int size_block = 20;
    };
// }

#endif

