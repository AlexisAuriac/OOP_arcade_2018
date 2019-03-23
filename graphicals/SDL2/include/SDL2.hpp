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

static const std::unordered_map<SDLKey, event_key> event_tab = {
    {'A', A},
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
    {'^[', Escape},
    {'[', LBracket},
    {']', RBracket},
    {';', Semicolon},
    {'Comma', Comma},
    {'Period', Period},
    {'Quote', Quote},
    {'Slash', Slash},
    {'Backslash', Backslash},
    {'Tilde', Tilde},
    {'Equal', Equal},
    {'Hyphen', Hyphen},
    {'Space', Space},
    {'Enter', Enter},
    {'Backspace', Backspace},
    {'Tab', Tab},
    {'PageUp', PageUp},
    {'PageDown', PageDown},
    {'End', End},
    {'Home', Home},
    {'Insert', Insert},
    {'Delete', Delete},
    {'Add', Add},
    {'Subtract', Subtract},
    {'Multiply', Multiply},
    {'Divide', Divide},
    {'Left', Left},
    {'Right', Right},
    {'Up', Up},
    {'Down', Down},
    {'F1', F1},
    {'F2', F2},
    {'F3', F3},
    {'F4', F4},
    {'F5', F5},
    {'F6', F6},
    {'F7', F7},
    {'F8', F8},
    {'F9', F9},
    {'F10', F10},
    {'F11', F11},
    {'F12', F12},
    {'F13', F13},
    {'F14', F14},
    {'F15', F15},
};

/*
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

const sf::Color CONNECT_COLORS[NB_COLORS] = {
    
    [BLACK] = sf::Color::Black,
    [BLUE] = sf::Color::Blue,
    [GREEN] = sf::Color::Green,
    [CYAN] = sf::Color::Cyan,
    [RED] = sf::Color::Red,
    [MAGENTA] = sf::Color::Magenta,
    [WHITE] = sf::Color::White,
    [GRAY] = sf::Color (127, 127, 127, 255),
    [YELLOW] = sf::Color::Yellow,
    
};

typedef int color_t;
*/
typedef struct textParams {
    /*
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
    */
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
        //void drawSquare(int x, int y, color_t color);
        void closeWindow();

    private:
        SDL_Surface *ecran = nullptr;
        const int size_window_width = 700;
        const int size_window_height = 60;
        const int size_block = 20;
    };
// }

#endif

