/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the interface for all graphic libraries.
*/

#ifndef IGRAPHIC_LIB_HPP
#define IGRAPHIC_LIB_HPP

#include <iostream>
#include <string>

namespace arc::gl {
    static const char ENTRY_POINT_NAME[] = "entryPoint";

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
        KeyCount
    };

    using event_t = int;

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

    using color_t = int;

    using textParams_t = struct textParams {
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
    };

    class IGraphicLib {
        public:
            virtual ~IGraphicLib() = default;
            virtual void openWindow() = 0;
            virtual void closeWindow() = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
            virtual int getCols() = 0;
            virtual int getLines() = 0;
            virtual void printText(
                const std::string &str,
                const textParams_t &params) = 0;
            virtual event_t getEvent() = 0;
            virtual void drawSquare(int x, int y, color_t color) = 0;
    };
}

#endif
