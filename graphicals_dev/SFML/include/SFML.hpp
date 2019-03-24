/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for ncurses.
*/

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "IGraphicLib.hpp"

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

static const std::unordered_map<sf::Keyboard::Key, event_key> event_tab = {
    {sf::Keyboard::A, A},
    {sf::Keyboard::B, B},
    {sf::Keyboard::C, C},
    {sf::Keyboard::D, D},
    {sf::Keyboard::E, E},
    {sf::Keyboard::F, F},
    {sf::Keyboard::G, G},
    {sf::Keyboard::H, H},
    {sf::Keyboard::I, I},
    {sf::Keyboard::J, J},
    {sf::Keyboard::K, K},
    {sf::Keyboard::L, L},
    {sf::Keyboard::M, M},
    {sf::Keyboard::N, N},
    {sf::Keyboard::O, O},
    {sf::Keyboard::P, P},
    {sf::Keyboard::Q, Q},
    {sf::Keyboard::R, R},
    {sf::Keyboard::S, S},
    {sf::Keyboard::T, T},
    {sf::Keyboard::U, U},
    {sf::Keyboard::V, V},
    {sf::Keyboard::W, W},
    {sf::Keyboard::X, X},
    {sf::Keyboard::Y, Y},
    {sf::Keyboard::Z, Z},
    {sf::Keyboard::Num0, Num0},
    {sf::Keyboard::Num1, Num1},
    {sf::Keyboard::Num2, Num2},
    {sf::Keyboard::Num3, Num3},
    {sf::Keyboard::Num4, Num4},
    {sf::Keyboard::Num5, Num5},
    {sf::Keyboard::Num6, Num6},
    {sf::Keyboard::Num7, Num7},
    {sf::Keyboard::Num8, Num8},
    {sf::Keyboard::Num9, Num9},
    {sf::Keyboard::Escape, Escape},
    {sf::Keyboard::LBracket, LBracket},
    {sf::Keyboard::RBracket, RBracket},
    {sf::Keyboard::Semicolon, Semicolon},
    {sf::Keyboard::Comma, Comma},
    {sf::Keyboard::Period, Period},
    {sf::Keyboard::Quote, Quote},
    {sf::Keyboard::Slash, Slash},
    {sf::Keyboard::Backslash, Backslash},
    {sf::Keyboard::Tilde, Tilde},
    {sf::Keyboard::Equal, Equal},
    {sf::Keyboard::Hyphen, Hyphen},
    {sf::Keyboard::Space, Space},
    {sf::Keyboard::Enter, Enter},
    {sf::Keyboard::Backspace, Backspace},
    {sf::Keyboard::Tab, Tab},
    {sf::Keyboard::PageUp, PageUp},
    {sf::Keyboard::PageDown, PageDown},
    {sf::Keyboard::End, End},
    {sf::Keyboard::Home, Home},
    {sf::Keyboard::Insert, Insert},
    {sf::Keyboard::Delete, Delete},
    {sf::Keyboard::Add, Add},
    {sf::Keyboard::Subtract, Subtract},
    {sf::Keyboard::Multiply, Multiply},
    {sf::Keyboard::Divide, Divide},
    {sf::Keyboard::Left, Left},
    {sf::Keyboard::Right, Right},
    {sf::Keyboard::Up, Up},
    {sf::Keyboard::Down, Down},
    {sf::Keyboard::F1, F1},
    {sf::Keyboard::F2, F2},
    {sf::Keyboard::F3, F3},
    {sf::Keyboard::F4, F4},
    {sf::Keyboard::F5, F5},
    {sf::Keyboard::F6, F6},
    {sf::Keyboard::F7, F7},
    {sf::Keyboard::F8, F8},
    {sf::Keyboard::F9, F9},
    {sf::Keyboard::F10, F10},
    {sf::Keyboard::F11, F11},
    {sf::Keyboard::F12, F12},
    {sf::Keyboard::F13, F13},
    {sf::Keyboard::F14, F14},
    {sf::Keyboard::F15, F15},
};


namespace arc::gl {
    class SFML : public IGraphicLib {
    public:
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

        static const int WINDOW_WIDTH = 1080;
        static const int WINDOW_HEIGHT = 720;
        static const int BLOCK_SIZE = 20;

        const char *FONT_PATH = "./assets/arial.ttf";

    public:
        SFML();
        void openWindow() override;
        event_key getEvent() override;
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
        sf::RenderWindow _window;
        sf::Font _font;
        sf::Text _text;
    };
}

#endif